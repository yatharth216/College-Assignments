#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, '.')), currentPlayer('X') {}

    void printBoard() {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '.') {
            return false; // Invalid move
        }
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
        return true;
    }

    char checkWinner() {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.') {
                return board[i][0];
            }
        }
        // Check columns
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '.') {
                return board[0][j];
            }
        }
        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') {
            return board[0][0];
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.') {
            return board[0][2];
        }
        return '.'; // No winner yet
    }
};

int main() {
    TicTacToe game;
    int row, col;
    while (true) {
        game.printBoard();
        cout << "Player " << game.getCurrentPlayer() << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;
        if (game.makeMove(row, col)) {
            char winner = game.checkWinner();
            if (winner != '.') {
                game.printBoard();
                cout << "Player " << winner << " wins!" << endl;
                break;
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
    return 0;
}