#include <SFML/Audio.hpp>
#include "Graphics.h"
#include "Logic.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Eggy of Tawan&Nont !!!");

    
    sf::Music bgMusic;
    if (!bgMusic.openFromFile("Free-Free-Lofi-Music-_For-YouTube_-After-the-Rain-by-Tokyo-Music-Walker.ogg"))
    {
        std::cerr << "Error loading music file!" << std::endl;
        return -1;
    }
    bgMusic.setLoop(true); 
    bgMusic.play();

    Graphics UI;
    UI.LoadAssets();

    mainMenu mainmenu(window.getSize().x, window.getSize().y);
    GameState gamestate = GameState::MENU;
    PlayerTurn playerturn = PlayerTurn::NONT;

    CountdownTimer cdtime(-1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (gamestate == GameState::PLAY)
            {
                UI.checkbackstage(event, gamestate);
                UI.draggingeggy(event, playerturn);
            }
            if (gamestate == GameState::TUTORIAL)
            {
                UI.checkbackstage(event, gamestate);
            }
        }

        if (gamestate == GameState::MENU) {
            mainmenu.changecolorbuttonmenu(window);
            mainmenu.changestatebutton(gamestate, window);
        }
        if (gamestate == GameState::PLAY) {
            UI.changecolorsq99(window);
            UI.draggingeggyandblabla(window);

            if (cdtime.getTimeLeft() == -4) {
                if (playerturn == PlayerTurn::TAWAN) playerturn = PlayerTurn::NONT;
                else playerturn = PlayerTurn::TAWAN;
                cdtime.reset();
            }
            cdtime.update();
            std::cout << cdtime.getTimeLeft();
        }

        window.clear();
        switch (gamestate) {
        case GameState::MENU:
            mainmenu.drawmenu(window, UI.bg_menu);
            break;
        case GameState::PLAY:
            UI.drawplay(window);
            break;
        case GameState::TUTORIAL:
            window.draw(UI.backarrowcream);
            break;
        default:
            break;
        }
        window.display();
    }

    return 0;
}
