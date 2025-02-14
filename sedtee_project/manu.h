#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#define MAX_ITEM 3

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
