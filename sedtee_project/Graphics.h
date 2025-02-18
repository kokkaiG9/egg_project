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
	bool isDragging = false;
	int selectedeggy1small = -1, selectedeggy2small = -1;
	int selectedeggy1mid = -1, selectedeggy2mid = -1;
	int selectedeggy1large = -1, selectedeggy2large = -1;
	sf::Vector2f offset;
public:
	std::vector<sf::Sprite> eggy1small; 
	std::vector<sf::Sprite> eggy1mid;
	std::vector<sf::Sprite> eggy1large;
	std::vector<sf::Sprite> eggy2small; 
	std::vector<sf::Sprite> eggy2mid;
	std::vector<sf::Sprite> eggy2large; 
	sf::Sprite bg_menu;
	sf::Sprite bg_play;

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