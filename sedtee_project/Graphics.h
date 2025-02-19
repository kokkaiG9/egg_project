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
	sf::Texture texturebackarrow;
	bool isDragging = false;
	int selectedeggy1small = -1, selectedeggy2small = -1;
	int selectedeggy1mid = -1, selectedeggy2mid = -1;
	int selectedeggy1large = -1, selectedeggy2large = -1;
	sf::Vector2f offset;
	int Numeggy1smallinframe = NULL, Numeggy1midinframe = NULL, Numeggy1largeinframe = NULL;
	int Numeggy2smallinframe = NULL, Numeggy2midinframe = NULL, Numeggy2largeinframe = NULL;

public:
	std::vector<sf::Sprite> eggy1small; // 3ตัว
	std::vector<sf::Sprite> eggy1mid; // 3ตัว
	std::vector<sf::Sprite> eggy1large; // 2ตัว
	std::vector<sf::Sprite> eggy2small; // 3ตัว
	std::vector<sf::Sprite> eggy2mid; // 3ตัว
	std::vector<sf::Sprite> eggy2large; // 2ตัว
	std::vector<sf::Sprite> number; // 0,1,2,3
	std::vector<sf::Sprite> eggy1frame; // 3 frames
	std::vector<sf::Sprite> eggy2frame; // 3frames
	sf::Sprite bg_menu;
	sf::Sprite bg_play;
	sf::Sprite backarrow;

	void LoadAssets();
	void drawplay(sf::RenderWindow&);
	void draggingeggy(sf::Event);
	void draggingeggyandblabla(sf::RenderWindow&);
	void checkbackstage(sf::Event, GameState&);
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