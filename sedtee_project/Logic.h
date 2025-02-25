#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class CountdownTimer {
public:
    CountdownTimer(int startTime) : timeLeft(startTime) {}

    // Call this function every frame to update the timer
    void update() {
        if (clock.getElapsedTime().asSeconds() >= 1) {
            if (timeLeft > -4) {
                timeLeft--;
            }
            clock.restart();
        }
    }

    // Reset the timer to the starting time
    void reset() {
        timeLeft = 10;  // Reset to 20 seconds
    }

    // Return the time left in seconds
    int getTimeLeft() const {
        return timeLeft;
    }

private:
    int timeLeft;
    sf::Clock clock;  // Used to track elapsed time
};