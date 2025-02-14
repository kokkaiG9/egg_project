#include "Graphics.h"

void Graphics::LoadAssets() {
	//load eggy1
	textureeggy1.loadFromFile("allpng\\eggy1.png");
	sf::Sprite eggypng1;
	eggypng1.setTexture(textureeggy1);
	for (int i = 0; i < 3; i++) {
		eggy1.push_back(eggypng1);
	}

	//load eggy2
	textureeggy2.loadFromFile("allpng\\eggy2.png");
	sf::Sprite eggypng2;
	eggypng2.setTexture(textureeggy2);
	for (int i = 0; i < 3; i++) {
		eggy2.push_back(eggypng2);
	}

	//setScale eggy1,2
	float scale = 0.75;
	for (int i = 0; i < 3; i++) {
		eggy1[i].setScale(scale, scale);
		eggy2[i].setScale(scale, scale);
		scale += 0.25;
	}
}

//¢Í§à¡éÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒ
//¢Í§à¡éÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒ
//¢Í§à¡éÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒÒ

#include "Manu.h"
Manu::Manu(float width, float height)
{
	if (!font.loadFromFile("Montserrat-Italic-VariableFont_wght.ttf")) {

	}
	/*sf::Text scoretext("Score", font, 80);*/
	menu[0].setFont(font);
	menu[0].setCharacterSize(100);
	menu[0].setFillColor(sf::Color::White);
	//menu[0].setFillColor(sf::Color(250,0,100); //RGB
	//menu[0].setStyle(sf::Text::Style::Underlined | sf::Text::Style::Italic);//¢Õ´àÊé¹ãµé¢éÍ¤ÇÒÁ 4 µÑÇàÍÕÂ§ 2
	//menu[0].setOutlineColor(sf::Color::Green); //àÊé¹¢Íº
	//menu[0].setOutlineThickness(2); //¢ÍºË¹Ò
	menu[0].setString("Play");
	menu[0].setOrigin(menu[0].getGlobalBounds().width / 2, menu[0].getGlobalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM + 1) * 1));
	/*if (menu[0].getGlobalBounds().contain(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		menu[0].setFillColor(sf::Color::Red);
	}*/

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("ggg");
	menu[1].setOrigin(menu[1].getGlobalBounds().width / 2, menu[1].getGlobalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("ezezeze");
	menu[2].setOrigin(menu[2].getGlobalBounds().width / 2, menu[2].getGlobalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM + 1) * 3));


}
Manu::~Manu()
{

}

void Manu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < MAX_ITEM; i++) {
		window.draw(menu[i]);
	}
}

