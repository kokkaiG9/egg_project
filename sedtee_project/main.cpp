#include "Graphics.h"
#include "Logic.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Eggy of Tawan&Nont !!!");

	Graphics UI;
	UI.LoadAssets();

	mainMenu mainmenu(window.getSize().x, window.getSize().y);
	GameState gamestate = GameState::MENU;


	CountdownTimer timer(10);


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
			mainmenu.changecolorbuttonmenu(window);		// ����¹�ջ���˹��menu�͹����������
			mainmenu.changestatebutton(gamestate, window);		// ��������¹˹����
		}
		if (gamestate == GameState::PLAY) {
			UI.changecolorsq99(window);		// ����¹�յ��ҧ�����������
			UI.draggingeggyandblabla(window);		// dragging egg1,2
		}

		if (timer.getTimeLeft() == 0) {
			timer.reset();
		}
		timer.update();
		std::cout << timer.getTimeLeft() << std::endl;


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

