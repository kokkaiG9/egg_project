#pragma once
#include <SFML/Audio.hpp>

struct Sound {
private:
	sf::SoundBuffer clickbuttonmenu;
	sf::SoundBuffer ITAWAN;
	sf::SoundBuffer INONT;
public:
	sf::Music bgmusic;
	sf::Sound soundclickbuttonmenu;
	sf::Sound soundITAWAN;
	sf::Sound soundINONT;

	void loadsound();
};
