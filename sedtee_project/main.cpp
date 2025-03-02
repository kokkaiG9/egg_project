#include "Graphics.h"
#include "Logic.h"
#include "Sound.h"
#include <SFML/Audio.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Eggy of Tawan&Nont !!!", sf::Style::Close);
	
	// SOUND
	Sound sound;
	sound.loadsound();
	sound.bgmusic.play();

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
				UI.checkbackstage(event, gamestate, sound.soundclickbuttonmenu);
				UI.draggingeggy(event, playerturn);		// draggingeggy
			}
			if (gamestate == GameState::TUTORIAL)
			{
				UI.checkbackstage(event, gamestate, sound.soundclickbuttonmenu);
			}
			if (gamestate == GameState::END)
			{
				eenndd.changecolorbutton_end(window);
				eenndd.changestate_end_button(gamestate, window, winner, sound.soundclickbuttonmenu, sound.bgmusic);
			}
		}

	//GAMESTATE::MENU
		if (gamestate == GameState::MENU) {
			mainmenu.changecolorbuttonmenu(window);
			mainmenu.changestatebutton(gamestate, window, sound.soundclickbuttonmenu, sound.soundWelcomePlay);
		}

	//GAMESTATE::PLAY
		if (gamestate == GameState::PLAY) {
			UI.changecolorsq99(window);		// changecolorboard
			UI.draggingeggyandblabla(window, sound.soundITAWAN, sound.soundINONT); // draggingeggy & blabla
			checkwinner.grid(UI.board);
			if (UI.endturn) {
				cdtime.setTimeLeft(-1);
				UI.endturn = false;
			}
			// time-countdown per turn
			if (cdtime.getTimeLeft() == -1 || cdtime.getTimeLeft() == -2 || cdtime.getTimeLeft() == -3) {
				playerturn = PlayerTurn::NOONE;
			}
			else if (cdtime.getTimeLeft() == -4) {
				if (turn % 2 == 1) playerturn = PlayerTurn::TAWAN;
				else playerturn = PlayerTurn::NONT;
				turn++;
				cdtime.reset();
			}
			cdtime.update();
			// checkwinner
			winner = checkwinner.checkWinner(UI.Numeggy1smallinframe, UI.Numeggy1midinframe, UI.Numeggy1largeinframe, UI.Numeggy2smallinframe, UI.Numeggy2midinframe, UI.Numeggy2largeinframe, playerturn);
			if (winner == 1 || winner == 2) {
				if(cdtime.getTimeLeft() == -1) sound.soundVictory.play();		//sound for winner
				if (cdtime.getTimeLeft() == -4) {
					gamestate = GameState::END;
				}
			}
		}

	// GAMESTATE::END
		// clear all data 
		if (gamestate == GameState::END) {
			if (turn != 1) {						//start gamestate::end sound  &  stop bgmusic
				sound.bgmusic.pause();
				sound.soundWelcomeEnd.play();
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					UI.board[i][j] = 0;
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					UI.checksize[i][j] = 0;
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

//DISPLAY
		window.clear();

		switch (gamestate) {
		case GameState::MENU:
			mainmenu.drawmenu(window, UI.bg_menu);
			break;
		case GameState::PLAY:
			UI.drawplay(window, cdtime.getTimeLeft(), playerturn);
			break;
		case GameState::TUTORIAL:
			window.draw(UI.bg_tutorial);
			UI.drawbackarrow(window);		
			break;
		case GameState::END:
			UI.drawend(window, winner);
			eenndd.drawbacktext(window);
			break;
		default:
			break;
		}

		window.display();
	}



	return 0;
}