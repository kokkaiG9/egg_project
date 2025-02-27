#include "Graphics.h"
#include "Logic.h"
#include <SFML/Audio.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Eggy of Tawan&Nont !!!", sf::Style::Close);

// SOUND BACKGROUND
	sf::Music bgMusic;
	if (!bgMusic.openFromFile("Free-Free-Lofi-Music-_For-YouTube_-After-the-Rain-by-Tokyo-Music-Walker.ogg"))
	{
		std::cerr << "Error loading music file!" << std::endl;
		return -1;
	}
	bgMusic.setVolume(10);		// suggestion: turn volume window to 60
	bgMusic.setLoop(true);
	bgMusic.play();
// UI
	Graphics UI;
	UI.LoadAssets();
	mainMenu mainmenu(window.getSize().x, window.getSize().y);
	END eenndd(window.getSize().x, window.getSize().y);
// GAMEPLAY
	GameState gamestate = GameState::MENU;
	PlayerTurn playerturn = PlayerTurn::NOONE;
	CountdownTimer cdtime;
	cdtime.setTimeLeft(-1);
	int turn = 1;
	TicTacToe checkwinner;
	int winner;

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
			if (gamestate == GameState::END)
			{
				//UI.checkbackstage(event, gamestate);
			}
		}

		if (gamestate == GameState::MENU) {
			mainmenu.changecolorbuttonmenu(window);		// menu:changecolorbutton
			mainmenu.changestatebutton(gamestate, window);		// change GAMESTAGE
		}
		if (gamestate == GameState::PLAY) {
			UI.changecolorsq99(window);		// play:changecolorboard
			UI.draggingeggyandblabla(window);		// dragging egg1,2
			checkwinner.grid(UI.board);
		// time-countdown per turn
			if (cdtime.getTimeLeft() == -1 || cdtime.getTimeLeft() == -2 || cdtime.getTimeLeft() == -3 || cdtime.getTimeLeft() == -4) {
				playerturn = PlayerTurn::NOONE;
			}
			else if (cdtime.getTimeLeft() == -5) {
				if (turn%2 == 1) playerturn = PlayerTurn::TAWAN;
				else playerturn = PlayerTurn::NONT;
				turn++;
				cdtime.reset();
			}
			cdtime.update();

			winner = checkwinner.checkWinner(UI.Numeggy1midinframe, UI.Numeggy1largeinframe, UI.Numeggy2midinframe, UI.Numeggy2largeinframe);
			if (winner == 1) {
				std::cout << "winner: TAWAN\n";
				gamestate = GameState::END;
			}
			else if (winner == 2) {
				std::cout << "winner: NONT\n";
				gamestate = GameState::END;
			}
		}

		if (gamestate == GameState::TUTORIAL) {}
	// clear all data 
		if (gamestate == GameState::END) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					UI.board[i][j] = 0;
				}
			}
			UI.Numeggy1smallinframe = NULL, UI.Numeggy1midinframe = NULL, UI.Numeggy1largeinframe = NULL;
			UI.Numeggy2smallinframe = NULL, UI.Numeggy2midinframe = NULL, UI.Numeggy2largeinframe = NULL;
			playerturn = PlayerTurn::NOONE;
			turn = 1;
			for (int i = 0; i < 3; i++) {
				UI.eggy1small[i].setPosition(515, 952.84);
				UI.eggy2small[i].setPosition(1405, 95);
			}
			for (int i = 0; i < 3; i++) {
				UI.eggy1mid[i].setPosition(340, 908.94);
				UI.eggy2mid[i].setPosition(1575, 124);
			}
			for (int i = 0; i < 2; i++) {
				UI.eggy1large[i].setPosition(125, 874.22);
				UI.eggy2large[i].setPosition(1790, 146);
			}
			cdtime.setTimeLeft(-1);
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
			case GameState::END:
				UI.drawend(window, winner);
				break;
			default:
				break;
		}

		window.display();
	}
	

	
	return 0;
}

// to do list : (2 days to die)
// - เช็คว่าวางไข่ตรงนี้ได้ไหม (ทอฟฟี่ทำป่าววะ ใช่เเหละ)
// - หน้า tutorial (someone) 
// - หน้า ending + summary (someone)

