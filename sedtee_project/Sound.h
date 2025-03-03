#pragma once
#include "Graphics.h"
#include <SFML/Audio.hpp>

class Sound {
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

	void loadsound() {
		bgmusic.openFromFile("allogg\\bgmusic.ogg");
		bgmusic.setVolume(6);
		bgmusic.setLoop(true);

		clickbuttonmenu.loadFromFile("allogg\\mouseclickmenu.ogg");
		soundclickbuttonmenu.setBuffer(clickbuttonmenu);
		soundclickbuttonmenu.setVolume(20);

		INONT.loadFromFile("allogg\\inont.ogg");
		soundINONT.setBuffer(INONT);
		soundINONT.setVolume(40);
		ITAWAN.loadFromFile("allogg\\itawan.ogg");
		soundITAWAN.setBuffer(ITAWAN);
		soundITAWAN.setVolume(25);

		welcomeplay.loadFromFile("allogg\\PlaySoundEffect.ogg");
		soundWelcomePlay.setBuffer(welcomeplay);
		soundWelcomePlay.setVolume(7);
		welcomeend.loadFromFile("allogg\\EndSoundEffect.ogg");
		soundWelcomeEnd.setBuffer(welcomeend);
		soundWelcomeEnd.setVolume(20);
		victory.loadFromFile("allogg\\VictorySoundEffect.ogg");
		soundVictory.setBuffer(victory);
		soundVictory.setVolume(40);
	}
};
