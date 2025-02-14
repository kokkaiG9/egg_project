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

