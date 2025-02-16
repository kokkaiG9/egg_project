#include "Graphics.h"
// Warning: หากท่านเลื่อนหัวตะวันเเละหัวนนท์ไปเรื่อยๆเเล้วหน้าจอเกิดดำขึ้นมา โปรดรู้ไว้ว่าไม่ใช่ความผิดของท่านเเต่เป็นความผิดส่วนcode dragging...ไว้จะมาเเก้นะจุ้ฟมั่วะ <3
// from: ktzboy sudcool


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Eggy of Tawan&Nont !!!");

	Graphics UI;
	UI.LoadAssets();

	mainMenu mainmenu(window.getSize().x, window.getSize().y);
	GameState gamestate = GameState::MENU;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (gamestate == GameState::PLAY) 
			{
				// dragging eggy1,2
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					for (int i = 0; i < 3; i++)
					{
						if (UI.eggy1[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
						{
							UI.isDragging = true;
							UI.offset = UI.eggy1[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
							UI.selectedeggy1 = i;
							break;
						}
						else if (UI.eggy2[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
						{
							UI.isDragging = true;
							UI.offset = UI.eggy2[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
							UI.selectedeggy2 = i;
							break;
						}
					}
				}
				if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
					UI.isDragging = false;
					UI.selectedeggy1 = UI.selectedeggy2 = -1;
				}
			}
		}

		///////////////////menu not manu/////////////////////////////////////////

		if (mainmenu.menu[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) 
		{
			mainmenu.menu[0].setFillColor(sf::Color::Red);
		}
		else if (mainmenu.menu[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) 
		{
			mainmenu.menu[1].setFillColor(sf::Color::Red);
		}
		else if (mainmenu.menu[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) 
		{
			mainmenu.menu[2].setFillColor(sf::Color::Red);
		}
		else {
			mainmenu.menu[0].setFillColor(sf::Color::White);
			mainmenu.menu[1].setFillColor(sf::Color::White);
			mainmenu.menu[2].setFillColor(sf::Color::White);
		}

		/*if (event.type == sf::Event::MouseButtonReleased)
		{*/
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
		{
			if (mainmenu.menu[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) 
			{
				gamestate = GameState::PLAY;
			}
			else if (mainmenu.menu[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) 
			{
				gamestate = GameState::SETTINGS;
			}
			else if (mainmenu.menu[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) 
			{
				window.close();
			}

		}

		// dragging egg1,2
		if (UI.isDragging && UI.selectedeggy1 != -1)
		{
			UI.eggy1[UI.selectedeggy1].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) + UI.offset);
		}
		else if (UI.isDragging && UI.selectedeggy2 != -1)
		{
			UI.eggy2[UI.selectedeggy2].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) + UI.offset);
		}



		window.clear();

		switch (gamestate) {
			case GameState::MENU:
				mainmenu.draw(window, UI.bg_menu);
				break;
			case GameState::PLAY:
				UI.drawplay(window);
				break;
			case GameState::SETTINGS:
				break;
			default:
				break;
		}

		window.display();
	}
	

	
	return 0;
}

