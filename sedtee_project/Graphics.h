#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#define MAX_ITEM 3

class Graphics {
public:
	std::vector<sf::Sprite> eggy1; //eggy1[0](small) 3���, eggy1[1](mid) 2���, egg1[2](large) 3���
	std::vector<sf::Sprite> eggy2; //eggy2[0](small) 3���, eggy2[1](mid) 2���, egg2[2](large) 3���
	sf::Texture textureeggy1;
	sf::Texture textureeggy2;

	void LoadAssets();
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

	void draw(sf::RenderWindow& window);

};

enum class GameState {
	MENU,
	PLAY,
	SETTINGS,
	EXIT
};