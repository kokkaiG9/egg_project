#include "Graphics.h"


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
				UI.draggingeggy(event); // dragging eggy1,2
			}
		}

		mainmenu.changecolorbuttonmenu(window); // เปลี่ยนสีปุ่มหน้าmenuตอนเอาเมาส์ชี้
		mainmenu.changestatebutton(gamestate, window); // ปุ่มเปลี่ยนหน้าเกม
		UI.draggingeggyblabla(window); // dragging egg1,2


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

