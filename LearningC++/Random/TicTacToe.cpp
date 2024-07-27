#include <iostream>

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() : currentPlayer('X') {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard() const {
        std::cout << "  0 1 2\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << "|";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "  -+-+-\n";
        }
    }

    bool placeMark(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    bool checkWin() const {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool checkDraw() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    int row, col;
    bool win = false, draw = false;

    game.displayBoard();
    while (!win && !draw) {
        std::cout << "Player " << game.getCurrentPlayer() << ", enter row and column: ";
        std::cin >> row >> col;
        if (game.placeMark(row, col)) {
            game.displayBoard();
            win = game.checkWin();
            if (win) {
                std::cout << "Player " << game.getCurrentPlayer() << " wins!" << std::endl;
            } else {
                draw = game.checkDraw();
                if (draw) {
                    std::cout << "The game is a draw." << std::endl;
                } else {
                    game.switchPlayer();
                }
            }
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}
