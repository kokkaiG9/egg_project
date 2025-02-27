#include <iostream>
#include <vector>

using namespace std; // Avoids prefixing std:: before standard functions

// Define board size
const int BOARD_ROWS = 3;
const int BOARD_COLS = 3;

// Initialize board: each cell stores {player, size} (0 means empty)
vector<vector<pair<int, int>>> board(BOARD_ROWS, vector<pair<int, int>>(BOARD_COLS, {0, 0}));

// Available pieces for each player: index represents size (1-based)
vector<int> player1_pieces = {3, 3, 2}; // Pieces of size 1, 2, 3
vector<int> player2_pieces = {3, 3, 2};

// Function declarations (added missing semicolons)
bool canPlacePiece(int row, int col, int size, int player, const vector<vector<pair<int, int>>>& board, const vector<int>& available_pieces);
void placePiece(int row, int col, int size, int player, vector<vector<pair<int, int>>>& board, vector<int>& available_pieces);
void removePiece(int row, int col, vector<vector<pair<int, int>>>& board, vector<int>& available_pieces, int size, const pair<int, int>& previous_state);
void printBoard();

int main() {
    cout << "Initial Board:\n";
    printBoard();

    // Test placing a piece for Player 1
    if (canPlacePiece(2, 2, 2, 1, board, player1_pieces)) {
        placePiece(2, 2, 2, 1, board, player1_pieces);
    }
    cout << "\nBoard after placing player 1's piece (size 2) at (2,2):\n";
    printBoard();

    // Test placing a larger piece for Player 2
    if (canPlacePiece(2, 2, 1, 2, board, player2_pieces)) {
        placePiece(2, 2, 1, 2, board, player2_pieces);
    }
    cout << "\nBoard after Player 2 places a size 3 piece at (2,2):\n";
    printBoard();

    return 0;
}

// Function to check if a piece can be placed at a position
bool canPlacePiece(int row, int col, int size, int player, const vector<vector<pair<int, int>>>& board, const vector<int>& available_pieces) {
    // Bounds check
    if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_COLS) {
        return false;
    }

    // Check if the piece is available
    if (available_pieces[size - 1] <= 0) {
        return false;
    }

    // Check if the position is empty or can be replaced (larger piece overwrites smaller one)
    if (board[row][col].first == 0 || board[row][col].second < size) {
        return true;
    }

    return false;
}

// Function to place a piece
void placePiece(int row, int col, int size, int player, vector<vector<pair<int, int>>>& board, vector<int>& available_pieces) {
    board[row][col] = {player, size};
    available_pieces[size - 1]--;
}

// Function to remove a piece (restores previous state)
void removePiece(int row, int col, vector<vector<pair<int, int>>>& board, vector<int>& available_pieces, int size, const pair<int, int>& previous_state) {
    board[row][col] = previous_state;
    available_pieces[size - 1]++;
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            if (board[i][j].first == 0)
                cout << ". ";
            else
                cout << board[i][j].first << board[i][j].second << " ";
        }
        cout << endl;
    }
}
