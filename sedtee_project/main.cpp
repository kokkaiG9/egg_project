#include "Graphics.h"
#include "Logic.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Eggy of Tawan&Nont !!!");

	Graphics UI;
	UI.LoadAssets();

	mainMenu mainmenu(window.getSize().x, window.getSize().y);
	GameState gamestate = GameState::MENU;
	PlayerTurn playerturn = PlayerTurn::NONT;

	CountdownTimer cdtime(-1);

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
				UI.draggingeggy(event);		// dragging eggy1,2
			}
			if (gamestate == GameState::TUTORIAL)
			{
				UI.checkbackstage(event, gamestate);
			}
		}

		if (gamestate == GameState::MENU) {
			mainmenu.changecolorbuttonmenu(window);		// เปลี่ยนสีปุ่มหน้าmenuตอนเอาเมาส์ชี้
			mainmenu.changestatebutton(gamestate, window);		// ปุ่มเปลี่ยนหน้าเกม
		}
		if (gamestate == GameState::PLAY) {
			UI.changecolorsq99(window);		// เปลี่ยนสีตารางเวลาเมาส์ชี้
			UI.draggingeggyandblabla(window);		// dragging egg1,2
			
			if (cdtime.getTimeLeft() == -4) {		// countdown turn
				if (playerturn == PlayerTurn::TAWAN) playerturn = PlayerTurn::NONT;
				else playerturn = PlayerTurn::TAWAN;
				cdtime.reset();
			}
			cdtime.update();
			std::cout << cdtime.getTimeLeft();
		}


		window.clear();

		switch (gamestate) {
			case GameState::MENU:
				mainmenu.drawmenu(window, UI.bg_menu);
				break;
			case GameState::PLAY:
				UI.drawplay(window);
				break;
			case GameState::TUTORIAL:
				window.draw(UI.backarrowcream);
				break;
			default:
				break;
		}

		window.display();
	}
	

	
	return 0;
}

