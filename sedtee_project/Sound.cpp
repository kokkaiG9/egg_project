#include "Sound.h"

void Sound::loadsound() {
	bgmusic.openFromFile("allogg\\bgmusic.ogg");
	bgmusic.setVolume(6);
	bgmusic.setLoop(true);

	clickbuttonmenu.loadFromFile("allogg\\mouseclickmenu.ogg");
	soundclickbuttonmenu.setBuffer(clickbuttonmenu);
	soundclickbuttonmenu.setVolume(20);

	INONT.loadFromFile("allogg\\inont.ogg");
	soundINONT.setBuffer(INONT);
	soundINONT.setVolume(60);
	ITAWAN.loadFromFile("allogg\\itawan.ogg");
	soundITAWAN.setBuffer(ITAWAN);
	soundITAWAN.setVolume(45);
}