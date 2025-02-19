#include "Graphics.h"

void Graphics::LoadAssets() {
	// load number0,1,2,3
	texturenumber0.loadFromFile("allpng\\number0.png");
	texturenumber1.loadFromFile("allpng\\number1.png");
	texturenumber2.loadFromFile("allpng\\number2.png");
	texturenumber3.loadFromFile("allpng\\number3.png");
	sf::Sprite tempnumber;
	for (int i = 0; i < 4; i++) {
		if(i == 0) tempnumber.setTexture(texturenumber0);
		else if(i == 1) tempnumber.setTexture(texturenumber1);
		else if (i == 2) tempnumber.setTexture(texturenumber2);
		else tempnumber.setTexture(texturenumber3);
		number.push_back(tempnumber);
	}

	// load backarrow
	texturebackarrow.loadFromFile("allpng\\backarrow.png");
	backarrow.setTexture(texturebackarrow);

	// setPosition backarrow
	backarrow.setPosition(25, 25);

	// load bg_menu, bg_play
	texturebg_menu.loadFromFile("allpng\\bg_menu.png");
	texturebg_play.loadFromFile("allpng\\bg_play.png");
	bg_menu.setTexture(texturebg_menu);
	bg_play.setTexture(texturebg_play);

	// load eggy1frame, eggy2frame
	textureeggy1frame.loadFromFile("allpng\\eggy1frame.png");
	textureeggy2frame.loadFromFile("allpng\\eggy2frame.png");
	sf::Sprite tempeggy1frame;
	sf::Sprite tempeggy2frame;
	tempeggy1frame.setTexture(textureeggy1frame);
	tempeggy2frame.setTexture(textureeggy2frame);
	for (int i = 0; i < 3; i++) {
		eggy1frame.push_back(tempeggy1frame);
		eggy2frame.push_back(tempeggy2frame);
	}

	// setScale eggy1frame, eggy2frame
	{
		float s = 0.24, m = 0.34, l = 0.42;
		eggy1frame[0].setScale(s, s);
		eggy2frame[0].setScale(s, s);
		eggy1frame[1].setScale(m, m);
		eggy2frame[1].setScale(m, m);
		eggy1frame[2].setScale(l, l);
		eggy2frame[2].setScale(l, l);
	}

	// setPosition eggy1frame, eggy2frame
	eggy1frame[0].setPosition(455, 882.68);
	eggy2frame[0].setPosition(1345, 25);
	eggy1frame[1].setPosition(260, 810.88);
	eggy2frame[1].setPosition(1490, 25);
	eggy1frame[2].setPosition(25, 753.44);
	eggy2frame[2].setPosition(1685, 25);

	// load eggy1, eggy2
	textureeggy1small.loadFromFile("allpng\\eggy1small.png");
	textureeggy1mid.loadFromFile("allpng\\eggy1mid.png");
	textureeggy1large.loadFromFile("allpng\\eggy1large.png");
	textureeggy2small.loadFromFile("allpng\\eggy2small.png");
	textureeggy2mid.loadFromFile("allpng\\eggy2mid.png");
	textureeggy2large.loadFromFile("allpng\\eggy2large.png");
	sf::Sprite eggypng1small;
	sf::Sprite eggypng1mid;
	sf::Sprite eggypng1large;
	sf::Sprite eggypng2small;
	sf::Sprite eggypng2mid;
	sf::Sprite eggypng2large;
	eggypng1small.setTexture(textureeggy1small);
	eggypng1mid.setTexture(textureeggy1mid);
	eggypng1large.setTexture(textureeggy1large);
	eggypng2small.setTexture(textureeggy2small);
	eggypng2mid.setTexture(textureeggy2mid);
	eggypng2large.setTexture(textureeggy2large);
	for (int i = 0; i < 3; i++) {
		eggy1small.push_back(eggypng1small);
		eggy1mid.push_back(eggypng1mid);
		eggy2small.push_back(eggypng2small);
		eggy2mid.push_back(eggypng2mid);
		if (i < 2) {
			eggy1large.push_back(eggypng1large);
			eggy2large.push_back(eggypng2large);
		}
	}

	// setOrigin egg1,2
	for (int i = 0;i < 3;i++) {
		eggy1small[i].setOrigin(eggy1small[i].getLocalBounds().width / 2, eggy1small[i].getLocalBounds().height / 2);
		eggy2small[i].setOrigin(eggy2small[i].getLocalBounds().width / 2, eggy2small[i].getLocalBounds().height / 2);
		eggy1mid[i].setOrigin(eggy1mid[i].getLocalBounds().width / 2, eggy1mid[i].getLocalBounds().height / 2);
		eggy2mid[i].setOrigin(eggy2mid[i].getLocalBounds().width / 2, eggy2mid[i].getLocalBounds().height / 2);
		if (i < 2) {
			eggy1large[i].setOrigin(eggy1large[i].getLocalBounds().width / 2, eggy1large[i].getLocalBounds().height / 2);
			eggy2large[i].setOrigin(eggy2large[i].getLocalBounds().width / 2, eggy2large[i].getLocalBounds().height / 2);
		}
	}

	// setPosition egg1,2
	for (int i = 0; i < 3; i++) {
		eggy1small[i].setPosition(515, 952.84);
		eggy2small[i].setPosition(1405, 95);
	}
	for (int i = 0; i < 3; i++) {
		eggy1mid[i].setPosition(340, 908.94);
		eggy2mid[i].setPosition(1575, 124);
	}
	for (int i = 0; i < 2; i++) {
		eggy1large[i].setPosition(125, 874.22);
		eggy2large[i].setPosition(1790, 146);
	}
}

void Graphics::drawplay(sf::RenderWindow& window) {
	// draw background
	window.draw(bg_play);
	window.draw(backarrow);
	for (int i = 0; i < 3; i++) {
		// draw frame
		window.draw(eggy1frame[i]);
		window.draw(eggy2frame[i]);
		// draw Numeggy1small
		if (Numeggy1smallinframe == 0) {
			number[0].setPosition(455, 882.68);
			window.draw(number[0]);
		}
		else if (Numeggy1smallinframe == 1) {
			number[1].setPosition(455, 882.68);
			window.draw(number[1]);
		}
		else if (Numeggy1smallinframe == 2) {
			number[2].setPosition(455, 882.68);
			window.draw(number[2]);
		}
		else if (Numeggy1smallinframe == 3) {
			number[3].setPosition(455, 882.68);
			window.draw(number[3]);
		}
		// draw Numeggy1mid
		if (Numeggy1midinframe == 0) {
			number[0].setPosition(260, 810.88);
			window.draw(number[0]);
		}
		else if (Numeggy1midinframe == 1) {
			number[1].setPosition(260, 810.88);
			window.draw(number[1]);
		}
		else if (Numeggy1midinframe == 2) {
			number[2].setPosition(260, 810.88);
			window.draw(number[2]);
		}
		else if (Numeggy1midinframe == 3) {
			number[3].setPosition(260, 810.88);
			window.draw(number[3]);
		}
		// draw Numeggy1large
		if (Numeggy1largeinframe == 0) {
			number[0].setPosition(25, 753.44);
			window.draw(number[0]);
		}
		else if (Numeggy1largeinframe == 1) {
			number[1].setPosition(25, 753.44);
			window.draw(number[1]);
		}
		else if (Numeggy1largeinframe == 2) {
			number[2].setPosition(25, 753.44);
			window.draw(number[2]);
		}
		// draw Numeggy2small
		if (Numeggy2smallinframe == 0) {
			number[0].setPosition(1345, 25);
			window.draw(number[0]);
		}
		else if (Numeggy2smallinframe == 1) {
			number[1].setPosition(1345, 25);
			window.draw(number[1]);
		}
		else if (Numeggy2smallinframe == 2) {
			number[2].setPosition(1345, 25);
			window.draw(number[2]);
		}
		else if (Numeggy2smallinframe == 3) {
			number[3].setPosition(1345, 25);
			window.draw(number[3]);
		}
		// draw Numeggy2mid
		if (Numeggy2midinframe == 0) {
			number[0].setPosition(1490, 25);
			window.draw(number[0]);
		}
		else if (Numeggy2midinframe == 1) {
			number[1].setPosition(1490, 25);
			window.draw(number[1]);
		}
		else if (Numeggy2midinframe == 2) {
			number[2].setPosition(1490, 25);
			window.draw(number[2]);
		}
		else if (Numeggy2midinframe == 3) {
			number[3].setPosition(1490, 25);
			window.draw(number[3]);
		}
		// draw Numeggy2large
		if (Numeggy2largeinframe == 0) {
			number[0].setPosition(1685, 25);
			window.draw(number[0]);
		}
		else if (Numeggy2largeinframe == 1) {
			number[1].setPosition(1685, 25);
			window.draw(number[1]);
		}
		else if (Numeggy2largeinframe == 2) {
			number[2].setPosition(1685, 25);
			window.draw(number[2]);
		}
	}
	//draw eggy
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

	//reset Numeggyinframe
	Numeggy1smallinframe = Numeggy1midinframe = Numeggy1largeinframe = 0;
	Numeggy2smallinframe = Numeggy2midinframe = Numeggy2largeinframe = 0;
}

void Graphics::checkbackstage(sf::Event event, GameState& gamestate) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		if (backarrow.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			gamestate = GameState::MENU;
		}
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

void Graphics::draggingeggyandblabla(sf::RenderWindow& window) {
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

	if (!isDragging) {
		for (int i = 0; i < 3; i++) {
			if (eggy1frame[0].getGlobalBounds().contains(eggy1small[i].getPosition())) {
				eggy1small[i].setPosition(515, 952.84);
			}
			if (eggy1frame[1].getGlobalBounds().contains(eggy1mid[i].getPosition())) {
				eggy1mid[i].setPosition(340, 908.94);
			}
			if (i < 2 && eggy1frame[2].getGlobalBounds().contains(eggy1large[i].getPosition())) {
				eggy1large[i].setPosition(125, 874.22);
			}
			if (eggy2frame[0].getGlobalBounds().contains(eggy2small[i].getPosition())) {
				eggy2small[i].setPosition(1405, 95);
			}
			if (eggy2frame[1].getGlobalBounds().contains(eggy2mid[i].getPosition())) {
				eggy2mid[i].setPosition(1575, 124);
			}
			if (i < 2 && eggy2frame[2].getGlobalBounds().contains(eggy2large[i].getPosition())) {
				eggy2large[i].setPosition(1790, 146);
			}
		}
	}

	// สอดไส้/ของเเถม 
	// นับจำนวนไข่ที่อยู่ในเฟรม
	int n1s, n1m, n1l, n2s, n2m, n2l;
	n1s = n1m = n1l = n2s = n2m = n2l = 0;
	for (int i = 0; i < 3; i++) {
		if (eggy1frame[0].getGlobalBounds().contains(eggy1small[i].getPosition())) {
			n1s++;
		}
		if (eggy1frame[1].getGlobalBounds().contains(eggy1mid[i].getPosition())) {
			n1m++;
		}
		if (i < 2 && eggy1frame[2].getGlobalBounds().contains(eggy1large[i].getPosition())) {
			n1l++;
		}
		if (eggy2frame[0].getGlobalBounds().contains(eggy2small[i].getPosition())) {
			n2s++;
			}
		if (eggy2frame[1].getGlobalBounds().contains(eggy2mid[i].getPosition())) {
			n2m++;
		}
		if (i < 2 && eggy2frame[2].getGlobalBounds().contains(eggy2large[i].getPosition())) {
			n2l++;
		}
	}
	Numeggy1smallinframe = n1s;
	Numeggy1midinframe = n1m;
	Numeggy1largeinframe = n1l;
	Numeggy2smallinframe = n2s;
	Numeggy2midinframe = n2m;
	Numeggy2largeinframe = n2l;
}

mainMenu::mainMenu(float width, float height)
{
	if (!font.loadFromFile("Montserrat-ExtraBold.ttf")) {
		std::cerr << "Error: ไม่สามารถโหลดฟอนต์!" << std::endl;
	}
	/*sf::Text scoretext("Score", font, 80);*/
	menu[0].setFont(font);
	//menu[0].setCharacterSize(100);
	menu[0].setFillColor(sf::Color::White);
	//menu[0].setFillColor(sf::Color(250,0,100); //RGB
	//menu[0].setStyle(sf::Text::Style::Underlined | sf::Text::Style::Italic);//ขีดเส้นใต้ข้อความ 4 ตัวเอียง 2
	//menu[0].setOutlineColor(sf::Color::Green); //เส้นขอบ
	//menu[0].setOutlineThickness(2); //ขอบหนา
	menu[0].setCharacterSize(35);
	menu[0].setString("PLAY");
	menu[0].setOrigin(menu[0].getGlobalBounds().width / 2, menu[0].getGlobalBounds().height / 2);
	menu[0].setPosition(1607, 438);


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setCharacterSize(35);
	menu[1].setString("TUTORIAL");
	menu[1].setOrigin(menu[1].getGlobalBounds().width / 2, menu[1].getGlobalBounds().height / 2);
	menu[1].setPosition(1607, 652);

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setCharacterSize(35);
	menu[2].setString("EXIT");
	menu[2].setOrigin(menu[2].getGlobalBounds().width / 2, menu[2].getGlobalBounds().height / 2);
	menu[2].setPosition(1604, 864);


}
mainMenu::~mainMenu()
{

}

void mainMenu::drawmenu(sf::RenderWindow& window, sf::Sprite bg_menu) {
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
				gamestate = GameState::TUTORIAL;
			}
			else if (menu[2].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				window.close();
			}
		}
	}
}
