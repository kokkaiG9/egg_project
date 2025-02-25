#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class CountdownTimer {
public:
    CountdownTimer(int startTime) : timeLeft(startTime) {}

// update time !!!(call this function every frame)!!!
    void update() {
        if (clock.getElapsedTime().asSeconds() >= 1) {
            if (timeLeft > -5) {
                timeLeft--;
            }
            clock.restart();
        }
    }

// reset time
    void reset() {
        timeLeft = 20;      // time per turn
    }

// return timeleft
    int getTimeLeft() const {
        return timeLeft;
    }

private:
    int timeLeft;
    sf::Clock clock;
};