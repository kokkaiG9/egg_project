#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#define MAX_ITEM 3

enum class GameState {
	MENU,
	PLAY,
	TUTORIAL,
	EXIT,
	END
};

enum class PlayerTurn {
	TAWAN = 1,
	NONT = 2,
	NOONE = 0
};

class Graphics {
private:
	sf::Texture textureeggy1small;
	sf::Texture textureeggy1mid;
	sf::Texture textureeggy1large;
	sf::Texture textureeggy2small;
	sf::Texture textureeggy2mid;
	sf::Texture textureeggy2large;
	sf::Texture textureeggy1frame;
	sf::Texture textureeggy2frame;
	sf::Texture texturebg_menu;
	sf::Texture texturebg_play;
	sf::Texture texturebg_end1;
	sf::Texture texturebg_end2;
	sf::Texture texturebg_tutorial;
	sf::Texture texturenumber0;
	sf::Texture texturenumber1;
	sf::Texture texturenumber2;
	sf::Texture texturenumber3;
	sf::Texture texturebackarrowcream;
	sf::Texture texturebackarrowgreen;
	sf::Texture texture_sq99_11;
	sf::Texture texture_sq99_12;
	sf::Texture texture_sq99_13;
	sf::Texture texture_sq99_21;
	sf::Texture texture_sq99_22;
	sf::Texture texture_sq99_23;
	sf::Texture texture_sq99_31;
	sf::Texture texture_sq99_32;
	sf::Texture texture_sq99_33;
	sf::Texture texture_sq99green;
	sf::Texture texturecdtime[25];
	bool eggy1smallongrid[3] = { false, false, false };
	bool eggy1midongrid[3] = { false, false, false };
	bool eggy1largeongrid[2] = { false, false };
	bool eggy2smallongrid[3] = { false, false, false };
	bool eggy2midongrid[3] = { false, false, false };
	bool eggy2largeongrid[2] = { false, false };
	bool isDragging = false;
	int selectedeggy1small = -1, selectedeggy2small = -1;
	int selectedeggy1mid = -1, selectedeggy2mid = -1;
	int selectedeggy1large = -1, selectedeggy2large = -1;
	sf::Vector2f offset;

public:
	bool endturn = false;
	std::vector<sf::Sprite> eggy1small;		// n = 3
	std::vector<sf::Sprite> eggy1mid;		// n = 3
	std::vector<sf::Sprite> eggy1large;		// n = 2
	std::vector<sf::Sprite> eggy2small;		// n = 3
	std::vector<sf::Sprite> eggy2mid;		// n = 3
	std::vector<sf::Sprite> eggy2large;		// n = 2
	std::vector<sf::Sprite> number;			// (number of eggs) 0,1,2,3
	std::vector<sf::Sprite> eggy1frame;		// frames = 3
	std::vector<sf::Sprite> eggy2frame;		// frames = 3
	int Numeggy1smallinframe = NULL, Numeggy1midinframe = NULL, Numeggy1largeinframe = NULL;
	int Numeggy2smallinframe = NULL, Numeggy2midinframe = NULL, Numeggy2largeinframe = NULL;
	sf::Sprite bg_menu;
	sf::Sprite bg_play;
	sf::Sprite bg_tutorial;
	sf::Sprite bg_end1;
	sf::Sprite bg_end2;
	sf::Sprite sq99_11;
	sf::Sprite sq99_12;
	sf::Sprite sq99_13;
	sf::Sprite sq99_21;
	sf::Sprite sq99_22;
	sf::Sprite sq99_23;
	sf::Sprite sq99_31;
	sf::Sprite sq99_32;
	sf::Sprite sq99_33;
	sf::Sprite sq99green;
	sf::Sprite backarrowcream;
	sf::Sprite backarrowgreen;
	int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	int checksize[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	std::vector<sf::Sprite> cdtime;

	void LoadAssets();
	void draggingeggy(sf::Event, PlayerTurn);
	void draggingeggyandblabla(sf::RenderWindow&, sf::Sound&, sf::Sound&);
	void checkbackstage(sf::Event, GameState&, sf::Sound&);
	void changecolorsq99(sf::RenderWindow&);
	bool changecolorbacksarow(sf::RenderWindow&);
	void drawNumeggy(sf::RenderWindow&);
	void drawSq99(sf::RenderWindow&);
	void drawbackarrow(sf::RenderWindow&);
	void drawcdtime(sf::RenderWindow&, int, PlayerTurn);
	void drawEggy(sf::RenderWindow&, PlayerTurn);
	void drawplay(sf::RenderWindow&, int, PlayerTurn);
	void drawend(sf::RenderWindow&, int);
};

class mainMenu
{
private:
	int selectedIteem = 0;
	sf::Font font;

public:
	sf::Text menu[3];
	mainMenu(float width, float hight);
	~mainMenu();

	void changecolorbuttonmenu(sf::RenderWindow&);
	void changestatebutton(GameState&, sf::RenderWindow&, sf::Sound&, sf::Sound&);
	void drawmenu(sf::RenderWindow& , sf::Sprite);
};

class END
{
private:
	int selectedIteem = 0;
	sf::Font font_end;

public:
	sf::Text t_end;
	END(float width, float hight);
	~END();

	void changecolorbutton_end(sf::RenderWindow&);
	void changestate_end_button(GameState&, sf::RenderWindow&, int&, sf::Sound&, sf::Music&);
	void drawbacktext(sf::RenderWindow&);
};