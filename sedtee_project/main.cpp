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
				UI.checkbackstage(event, gamestate);
				UI.draggingeggy(event); // dragging eggy1,2
			}
			if (gamestate == GameState::TUTORIAL)
			{
				UI.checkbackstage(event, gamestate);
			}
		}

		mainmenu.changecolorbuttonmenu(window); // เปลี่ยนสีปุ่มหน้าmenuตอนเอาเมาส์ชี้
		mainmenu.changestatebutton(gamestate, window); // ปุ่มเปลี่ยนหน้าเกม
		UI.changecolorsq99(window);
		UI.draggingeggyandblabla(window); // dragging egg1,2


		window.clear();

		switch (gamestate) {
			case GameState::MENU:
				mainmenu.drawmenu(window, UI.bg_menu);
				break;
			case GameState::PLAY:
				UI.drawplay(window);
				UI.drawsq99(window);
				break;
			case GameState::TUTORIAL:
				window.draw(UI.backarrow);
				break;
			default:
				break;
		}

		window.display();
	}
	

	
	return 0;
}

