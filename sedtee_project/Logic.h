#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class CountdownTimer {
public:
    CountdownTimer() : timeLeft(0) {}

    void setTimeLeft(int startTime) {
        timeLeft = startTime;
    }

// update time !!!(call this function every frame)!!!
    void update() {
        if (clock.getElapsedTime().asSeconds() >= 1) {
            if (timeLeft > -4) {
                timeLeft--;
            }
            clock.restart();
        }
    }

// reset time
    void reset() {
        timeLeft = 10;      // time per turn
    }

// return timeleft
    int getTimeLeft() const {
        return timeLeft;
    }

private:
    int timeLeft;
    sf::Clock clock;
};

class TicTacToe {
public:
    int board[3][3];
    void grid(int grid[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = grid[i][j];
            }
        }
    }

    int checkWinner(int eggy1small, int eggy1mid, int eggy1large, int eggy2small, int eggy2mid, int eggy2large, PlayerTurn playerturn) {
        // ตรวจสอบแถว
        for (int row = 0; row < 3; row++) {
            if (board[row][0] != 0 && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                return board[row][0]; // คืนค่า 1 (นนท์) หรือ 2 (ตะวัน)
            }
        }
        // ตรวจสอบคอลัมน์
        for (int col = 0; col < 3; col++) {
            if (board[0][col] != 0 && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                return board[0][col];
            }
        }
        // ตรวจสอบแนวทแยงจากซ้ายไปขวา
        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return board[0][0];
        }
        // ตรวจสอบแนวทแยงจากขวาไปซ้าย
        if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return board[0][2];
        }
        // นับจำนวนหมากของแต่ละคน
        int countNont = 0, countTawan = 0;
        bool hasEmpty = false;

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == 1) countNont++;
                else if (board[row][col] == 2) countTawan++;
                else hasEmpty = true;
            }
        }

        // ถ้ามีช่องว่างอยู่ -> เกมยังไม่จบ
        if (hasEmpty) return 0;

        // ถ้ากระดานเต็มและไม่มีใครชนะ -> คนที่มีจำนวนหมากมากกว่าชนะ
        if ((eggy1large == 0 && eggy2large == 0 && (eggy1mid == 1 || eggy1mid == 0) && (eggy2mid == 1 || eggy2mid == 0) && playerturn == PlayerTurn::NOONE) || (eggy1small == 0 && eggy1mid == 0 && eggy1large == 0 && eggy2small == 0 && eggy2mid == 0 && eggy2large == 0 && playerturn == PlayerTurn::NOONE)) {
            if (countNont > countTawan) return 1;
            if (countTawan > countNont) return 2;
        }

        return -1; // เสมอกัน (ถ้าหมากเท่ากัน)
    }
};