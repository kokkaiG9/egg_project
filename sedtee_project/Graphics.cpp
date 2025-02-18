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
		eggy1small.push_back(eggypng1);
		eggy2small.push_back(eggypng2);
		eggy1mid.push_back(eggypng1);
		eggy2mid.push_back(eggypng2);
		if (i < 2) {
			eggy1large.push_back(eggypng1);
			eggy2large.push_back(eggypng2);
		}
	}

	texturebg_menu.loadFromFile("allpng\\bg_menu2.png");
	texturebg_play.loadFromFile("allpng\\bg_play.png");
	bg_menu.setTexture(texturebg_menu);
	bg_play.setTexture(texturebg_play);

	// setScale eggy1,2
	for (int i = 0; i < 3; i++) {
		eggy1small[i].setScale(0.3, 0.3);
		eggy2small[i].setScale(0.3, 0.3);
	}
	for (int i = 0; i < 3; i++) {
		eggy1mid[i].setScale(0.4, 0.4);
		eggy2mid[i].setScale(0.4, 0.4);
	}
	for (int i = 0; i < 2; i++) {
		eggy1large[i].setScale(0.5, 0.5);
		eggy2large[i].setScale(0.5, 0.5);
	}

	// setPosition egg1,2
	for (int i = 0; i < 3; i++) {
		eggy1small[i].setPosition(0, 0);
		eggy2small[i].setPosition(0, 500);
	}
	for (int i = 0; i < 3; i++) {
		eggy1mid[i].setPosition(600, 0);
		eggy2mid[i].setPosition(600, 500);
	}
	for (int i = 0; i < 2; i++) {
		eggy1large[i].setPosition(1200, 0);
		eggy2large[i].setPosition(1200, 500);
	}
}

void Graphics::drawplay(sf::RenderWindow& window) {
	window.draw(bg_play);
	for (int i = 0;i < 3;i++) {
		window.draw(eggy1small[i]);
		window.draw(eggy2small[i]);
	}
	for (int i = 0;i < 3;i++) {
		window.draw(eggy1mid[i]);
		window.draw(eggy2mid[i]);
	}
	for (int i = 0;i < 2;i++) {
		window.draw(eggy1large[i]);
		window.draw(eggy2large[i]);
	}
}

void Graphics::draggingeggy(sf::Event event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		for (int i = 0; i < 3; i++)
		{
			if (eggy1small[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isDragging = true;
				offset = eggy1small[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				selectedeggy1small = i;
				break;
			}
			else if (eggy2small[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isDragging = true;
				offset = eggy2small[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				selectedeggy2small = i;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (eggy1small[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isDragging = true;
				offset = eggy1small[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				selectedeggy1small = i;
				break;
			}
			else if (eggy2small[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isDragging = true;
				offset = eggy2small[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				selectedeggy2small = i;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (eggy1mid[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isDragging = true;
				offset = eggy1mid[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				selectedeggy1mid = i;
				break;
			}
			else if (eggy2mid[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isDragging = true;
				offset = eggy2mid[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				selectedeggy2mid = i;
				break;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			if (eggy1large[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isDragging = true;
				offset = eggy1large[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				selectedeggy1large = i;
				break;
			}
			else if (eggy2large[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isDragging = true;
				offset = eggy2large[i].getPosition() - sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				selectedeggy2large = i;
				break;
			}
		}
	}
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		isDragging = false;
		selectedeggy1small = selectedeggy2small = -1;
		selectedeggy1mid = selectedeggy2mid = -1;
		selectedeggy1large = selectedeggy2large = -1;
	}
}

void Graphics::draggingeggyblabla(sf::RenderWindow& window) {
	if (isDragging && selectedeggy1small != -1)
	{
		eggy1small[selectedeggy1small].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) + offset);
	}
	else if (isDragging && selectedeggy2small != -1)
	{
		eggy2small[selectedeggy2small].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) + offset);
	}
	else if (isDragging && selectedeggy1mid != -1)
	{
		eggy1mid[selectedeggy1mid].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) + offset);
	}
	else if (isDragging && selectedeggy2mid != -1)
	{
		eggy2mid[selectedeggy2mid].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) + offset);
	}
	else if (isDragging && selectedeggy1large != -1)
	{
		eggy1large[selectedeggy1large].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) + offset);
	}
	else if (isDragging && selectedeggy2large != -1)
	{
		eggy2large[selectedeggy2large].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) + offset);
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

void mainMenu::changecolorbuttonmenu(sf::RenderWindow& window) {
	if (menu[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		menu[0].setFillColor(sf::Color::Red);
	}
	else if (menu[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		menu[1].setFillColor(sf::Color::Red);
	}
	else if (menu[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		menu[2].setFillColor(sf::Color::Red);
	}
	else {
		menu[0].setFillColor(sf::Color::White);
		menu[1].setFillColor(sf::Color::White);
		menu[2].setFillColor(sf::Color::White);
	}
}

void mainMenu::changestatebutton(GameState& gamestate, sf::RenderWindow& window) {
	if (gamestate == GameState::MENU)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menu[0].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				gamestate = GameState::PLAY;
			}
			else if (menu[1].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				gamestate = GameState::SETTINGS;
			}
			else if (menu[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				window.close();
			}
		}
	}
}
