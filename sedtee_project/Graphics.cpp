#include "Graphics.h"

void Graphics::LoadAssets() {
	// load eggy1, eggy2, bg_menu, bg_play
	textureeggy1.loadFromFile("allpng\\eggy1.png");
	textureeggy2.loadFromFile("allpng\\eggy2.png");
	sf::Sprite eggypng1;
	sf::Sprite eggypng2;
	eggypng1.setTexture(textureeggy1);
	eggypng2.setTexture(textureeggy2);
	for (int i = 0; i < 3; i++) {
		eggy1.push_back(eggypng1);
		eggy2.push_back(eggypng2);
	}
	texturebg_menu.loadFromFile("allpng\\bg_menu.png");
	texturebg_play.loadFromFile("allpng\\bg_play.png");
	bg_menu.setTexture(texturebg_menu);
	bg_play.setTexture(texturebg_play);

	// setScale eggy1,2
	float scale = 0.5;
	for (int i = 0; i < 3; i++) {
		eggy1[i].setScale(scale, scale);
		eggy2[i].setScale(scale, scale);
		scale += 0.1;
	}

	// setPosiotion egg1,2
	float x = 0;
	for (int i = 0; i < 3; i++) {
		eggy1[i].setPosition(x, 0);
		eggy2[i].setPosition(x, 540);
		x += 200;
	}
}

void Graphics::drawplay(sf::RenderWindow& window) {
	window.draw(bg_play);
	for (int i = 0;i < 3;i++) {
		window.draw(eggy1[i]);
		window.draw(eggy2[i]);
	}
}

////////////////////////////////gggggggggggggggoooooooooooowwwwwwwwwwwwwwwwwww///////////////////////////////////////


mainMenu::mainMenu(float width, float height)
{
	if (!font.loadFromFile("Montserrat-ExtraBold.ttf")) {
		std::cerr << "Error: ไม่สามารถโหลดฟอนต์!" << std::endl;
	}
	/*sf::Text scoretext("Score", font, 80);*/
	menu[0].setFont(font);
	menu[0].setCharacterSize(100);
	menu[0].setFillColor(sf::Color::White);
	//menu[0].setFillColor(sf::Color(250,0,100); //RGB
	//menu[0].setStyle(sf::Text::Style::Underlined | sf::Text::Style::Italic);//ขีดเส้นใต้ข้อความ 4 ตัวเอียง 2
	//menu[0].setOutlineColor(sf::Color::Green); //เส้นขอบ
	//menu[0].setOutlineThickness(2); //ขอบหนา
	menu[0].setString("Play");
	menu[0].setOrigin(menu[0].getGlobalBounds().width / 2, menu[0].getGlobalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM + 1) * 1));


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("SETTING");//หรือจะใส่ tutorail  แทน
	menu[1].setOrigin(menu[1].getGlobalBounds().width / 2, menu[1].getGlobalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setOrigin(menu[2].getGlobalBounds().width / 2, menu[2].getGlobalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM + 1) * 3));


}
mainMenu::~mainMenu()
{

}

void mainMenu::draw(sf::RenderWindow& window, sf::Sprite bg_menu) {
	window.draw(bg_menu);
	for (int i = 0; i < MAX_ITEM; i++) {
		window.draw(menu[i]);
	}
}

