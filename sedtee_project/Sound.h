#pragma once
#include "Graphics.h"
#include <SFML/Audio.hpp>

struct Sound {
private:
	sf::SoundBuffer clickbuttonmenu;
	sf::SoundBuffer ITAWAN;
	sf::SoundBuffer INONT;
	sf::SoundBuffer welcomeplay;
	sf::SoundBuffer welcomeend;
	sf::SoundBuffer victory;
public:
	sf::Music bgmusic;
	sf::Sound soundclickbuttonmenu;
	sf::Sound soundITAWAN;
	sf::Sound soundINONT;
	sf::Sound soundWelcomePlay;
	sf::Sound soundWelcomeEnd;
	sf::Sound soundVictory;

	void loadsound();
};
