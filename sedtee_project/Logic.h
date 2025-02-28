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
        // ��Ǩ�ͺ��
        for (int row = 0; row < 3; row++) {
            if (board[row][0] != 0 && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                return board[row][0]; // �׹��� 1 (����) ���� 2 (���ѹ)
            }
        }
        // ��Ǩ�ͺ�������
        for (int col = 0; col < 3; col++) {
            if (board[0][col] != 0 && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                return board[0][col];
            }
        }
        // ��Ǩ�ͺ�Ƿ�§�ҡ����仢��
        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return board[0][0];
        }
        // ��Ǩ�ͺ�Ƿ�§�ҡ���仫���
        if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return board[0][2];
        }
        // �Ѻ�ӹǹ��ҡ�ͧ���Ф�
        int countNont = 0, countTawan = 0;
        bool hasEmpty = false;

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == 1) countNont++;
                else if (board[row][col] == 2) countTawan++;
                else hasEmpty = true;
            }
        }

        // ����ժ�ͧ��ҧ���� -> ���ѧ��診
        if (hasEmpty) return 0;

        // ��ҡ�дҹ������������ê�� -> ������ըӹǹ��ҡ�ҡ���Ҫ��
        if ((eggy1large == 0 && eggy2large == 0 && (eggy1mid == 1 || eggy1mid == 0) && (eggy2mid == 1 || eggy2mid == 0) && playerturn == PlayerTurn::NOONE) || (eggy1small == 0 && eggy1mid == 0 && eggy1large == 0 && eggy2small == 0 && eggy2mid == 0 && eggy2large == 0 && playerturn == PlayerTurn::NOONE)) {
            if (countNont > countTawan) return 1;
            if (countTawan > countNont) return 2;
        }

        return -1; // ���͡ѹ (�����ҡ��ҡѹ)
    }
};