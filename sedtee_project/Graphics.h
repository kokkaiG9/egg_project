#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#define MAX_ITEM 3

class Graphics {
public:
	std::vector<sf::Sprite> eggy1; //eggy1[0](small) 3µ—«, eggy1[1](mid) 2µ—«, egg1[2](large) 3µ—«
	std::vector<sf::Sprite> eggy2; //eggy2[0](small) 3µ—«, eggy2[1](mid) 2µ—«, egg2[2](large) 3µ—«
	sf::Texture textureeggy1;
	sf::Texture textureeggy2;
	float mouse_x, mouse_y;

	void LoadAssets();
};

//¢Õß‡°È“““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““
//¢Õß‡°È“““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““
//¢Õß‡°È“““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““““
class Manu
{
private:
	int selectedIteem = 0;
	sf::Font font;
	sf::Text menu[3];

public:
	Manu(float width, float hight);
	~Manu();

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();







};