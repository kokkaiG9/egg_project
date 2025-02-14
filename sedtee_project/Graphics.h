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
	float mouse_x, mouse_y;

	void LoadAssets();
};

//�ͧ�����������������������������������������������������������������������������������������������������������
//�ͧ�����������������������������������������������������������������������������������������������������������
//�ͧ�����������������������������������������������������������������������������������������������������������
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