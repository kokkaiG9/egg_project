#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#define MAX_ITEM 3

enum class GameState {
	MENU,
	PLAY,
	SETTINGS,
	EXIT
};

class Graphics {
private:
	sf::Texture textureeggy1;
	sf::Texture textureeggy2;
	sf::Texture texturebg_menu;
	sf::Texture texturebg_play;
public:
	std::vector<sf::Sprite> eggy1; // eggy1[0](small) 3ตัว, eggy1[1](mid) 2ตัว, egg1[2](large) 3ตัว
	std::vector<sf::Sprite> eggy2; // eggy2[0](small) 3ตัว, eggy2[1](mid) 2ตัว, egg2[2](large) 3ตัว
	sf::Sprite bg_menu;
	sf::Sprite bg_play;
	bool isDragging = false;
	int selectedeggy1 = -1, selectedeggy2 = -1;
	sf::Vector2f offset;

	void LoadAssets();
	void drawplay(sf::RenderWindow&);
	void draggingeggy(sf::Event);
	void draggingeggyblabla(sf::RenderWindow&);
};


/// //////////////////////////////////////////////////////ggggggggggggggggoooooooooooooooooooooooooowwwwwwwwwwwwwwwwwwwww//////////////////////////////

class mainMenu
{
private:
	int selectedIteem = 0;
	sf::Font font;

public:
	sf::Text menu[3];
	mainMenu(float width, float hight);
	~mainMenu();

	void draw(sf::RenderWindow& window, sf::Sprite);
	void changecolorbuttonmenu(sf::RenderWindow&);
	void changestatebutton(GameState&, sf::RenderWindow&);
};