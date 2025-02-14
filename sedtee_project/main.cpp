#include "Graphics.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Projecttest101");

	Graphics UI;

	UI.LoadAssets();

	float x = 0;
	for (int i = 1; i <= 3;i++) {
		UI.eggy1[i - 1].setPosition(x, 0);
		UI.eggy2[i - 1].setPosition(x, 500);
		x += 200;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();

		for (int i = 0; i < 3;i++) {
			window.draw(UI.eggy1[i]);
			window.draw(UI.eggy2[i]);
		}

		window.display();
	}

	return 0;
}