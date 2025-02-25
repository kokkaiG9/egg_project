#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#define MAX_ITEM 3

enum class GameState {
	MENU,
	PLAY,
	TUTORIAL,
	EXIT
};

enum class PlayerTurn {
	TAWAN,
	NONT,
	KT
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
	bool isDragging = false;
	int selectedeggy1small = -1, selectedeggy2small = -1;
	int selectedeggy1mid = -1, selectedeggy2mid = -1;
	int selectedeggy1large = -1, selectedeggy2large = -1;
	sf::Vector2f offset;
	int Numeggy1smallinframe = NULL, Numeggy1midinframe = NULL, Numeggy1largeinframe = NULL;
	int Numeggy2smallinframe = NULL, Numeggy2midinframe = NULL, Numeggy2largeinframe = NULL;

public:
	std::vector<sf::Sprite> eggy1small;		// 3ตัว
	std::vector<sf::Sprite> eggy1mid;		// 3ตัว
	std::vector<sf::Sprite> eggy1large;		// 2ตัว
	std::vector<sf::Sprite> eggy2small;		// 3ตัว
	std::vector<sf::Sprite> eggy2mid;		// 3ตัว
	std::vector<sf::Sprite> eggy2large;		// 2ตัว
	std::vector<sf::Sprite> number;			// 0,1,2,3
	std::vector<sf::Sprite> eggy1frame;		// 3frames
	std::vector<sf::Sprite> eggy2frame;		// 3frames
	sf::Sprite bg_menu;
	sf::Sprite bg_play;
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
	std::vector<sf::Sprite> cdtime;

	void LoadAssets();
	void draggingeggy(sf::Event, PlayerTurn);
	void draggingeggyandblabla(sf::RenderWindow&);
	void checkbackstage(sf::Event, GameState&);
	void changecolorsq99(sf::RenderWindow&);
	bool changecolorbacksarow(sf::RenderWindow&);
	void drawNumeggy(sf::RenderWindow&);
	void drawSq99(sf::RenderWindow&);
	void drawEggy(sf::RenderWindow&);
	void drawbackarrow(sf::RenderWindow&);
	void drawcdtime(sf::RenderWindow&, int, PlayerTurn);
	void drawplay(sf::RenderWindow&, int, PlayerTurn);
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

	void drawmenu(sf::RenderWindow& window, sf::Sprite);
	void changecolorbuttonmenu(sf::RenderWindow&);
	void changestatebutton(GameState&, sf::RenderWindow&);
};