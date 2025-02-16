#include "Graphics.h"

int main()
{
	sf::RenderWindow MENU(sf::VideoMode(1920, 1080), "MENU");
	/*sf::RenderWindow PLAY(sf::VideoMode(1920, 1080), "GAME");*/

	mainMenu mainmenu(MENU.getSize().x, MENU.getSize().y);
	GameState gamestate = GameState::MENU;
	Graphics UI;
	

	UI.LoadAssets();

	float x = 0;
	for (int i = 1; i <= 3;i++) {
		UI.eggy1[i - 1].setPosition(x, 0);
		UI.eggy2[i - 1].setPosition(x, 500);
		x += 200;
	}

	while (MENU.isOpen())
	{
		sf::Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				MENU.close();
			}
		}

		///////////////////menu not manu/////////////////////////////////////////

		if (mainmenu.menu[0].getGlobalBounds().contains(sf::Mouse::getPosition(MENU).x, sf::Mouse::getPosition(MENU).y)) 
		{
			mainmenu.menu[0].setFillColor(sf::Color::Red);
		}
		else if (mainmenu.menu[1].getGlobalBounds().contains(sf::Mouse::getPosition(MENU).x, sf::Mouse::getPosition(MENU).y)) 
		{
			mainmenu.menu[1].setFillColor(sf::Color::Red);
		}
		else if (mainmenu.menu[2].getGlobalBounds().contains(sf::Mouse::getPosition(MENU).x, sf::Mouse::getPosition(MENU).y)) 
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
			if (mainmenu.menu[0].getGlobalBounds().contains(sf::Mouse::getPosition(MENU).x, sf::Mouse::getPosition(MENU).y)) 
			{
				gamestate = GameState::PLAY;
			}
			else if (mainmenu.menu[1].getGlobalBounds().contains(sf::Mouse::getPosition(MENU).x, sf::Mouse::getPosition(MENU).y)) 
			{
				gamestate = GameState::SETTINGS;
			}
			else if (mainmenu.menu[2].getGlobalBounds().contains(sf::Mouse::getPosition(MENU).x, sf::Mouse::getPosition(MENU).y)) 
			{
				MENU.close();
			}

		}

		MENU.clear();
		mainmenu.draw(MENU);
		MENU.display();
			
		

		/*if (gamestate == GameState::PLAY)
		{
			sf::RenderWindow PLAY(sf::VideoMode(1920, 1080), "GAME");
			while (PLAY.isOpen())
			{
				sf::Event event;
				while (PLAY.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						PLAY.close();
					}
				}
			}

			MENU.close();
			PLAY.clear();
			for (int i = 0; i < 3; i++) {
				PLAY.draw(UI.eggy1[i]);
				PLAY.draw(UI.eggy2[i]);
			}
			PLAY.display();
		}*/



		/*MENU.clear();
		mainmenu.draw(MENU);
		MENU.display();*/



		/*switch (gamestate) {
		case GameState::MENU:
			std::cout << "อยู่ในหน้าเมนู\n";
			break;
		case GameState::PLAY:
			MENU.close();
			PLAY.clear();
			for (int i = 0; i < 3; i++) {
				PLAY.draw(UI.eggy1[i]);
				PLAY.draw(UI.eggy2[i]);
			}
			PLAY.display();
			break;
		default:
			std::cout << "?????\n";
			break;
		}*/

		/*if (gamestate == GameState::PLAY) {
			while (PLAY.isOpen())
			{
				sf::Event event;
				while (PLAY.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						PLAY.close();
					}
				}
				MENU.close();
				PLAY.clear();
				for (int i = 0; i < 3; i++) {
					PLAY.draw(UI.eggy1[i]);
					PLAY.draw(UI.eggy2[i]);
				}
				PLAY.display();

			}
			
		}*/
		
	/*	if (gamestate == GameState::MENU)
		{
			MENU.clear();
			mainmenu.draw(MENU);
			
		}

		else if (gamestate == GameState::PLAY)
		{
			for (int i = 0; i < 3; i++) {
				MENU.draw(UI.eggy1[i]);
				MENU.draw(UI.eggy2[i]);
			}
		}
		MENU.display();*/



	}
	

	
	


	return 0;
}

