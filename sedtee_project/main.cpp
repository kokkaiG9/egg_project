#include "Graphics.h"
#include "Logic.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Eggy of Tawan&Nont !!!");

	Graphics UI;
	UI.LoadAssets();

	mainMenu mainmenu(window.getSize().x, window.getSize().y);

	GameState gamestate = GameState::MENU;
	PlayerTurn playerturn = PlayerTurn::KT;
	CountdownTimer cdtime(-1);
	int turn = 1;

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
				UI.draggingeggy(event, playerturn);		// dragging eggy1,2
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
			// countdown turn
			if (cdtime.getTimeLeft() == -1 || cdtime.getTimeLeft() == -2 || cdtime.getTimeLeft() == -3 || cdtime.getTimeLeft() == -4) {
				playerturn = PlayerTurn::KT;
			}
			else if (cdtime.getTimeLeft() == -5) {
				if (turn%2 == 1) playerturn = PlayerTurn::TAWAN;
				else playerturn = PlayerTurn::NONT;
				turn++;
				cdtime.reset();
			}
			cdtime.update();
		}


		window.clear();
		
		switch (gamestate) {
			case GameState::MENU:
				mainmenu.drawmenu(window, UI.bg_menu);
				break;
			case GameState::PLAY:
				UI.drawplay(window, cdtime.getTimeLeft(), playerturn);
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

