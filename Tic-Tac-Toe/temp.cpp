#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <time.h>

enum State {
    ONGOING,
    DRAW,
    WIN
};

const char EMPTY = ' ';
const char PLAYER_SYMBOL = 'X';
const char AI_SYMBOL = 'O';

std::vector<char> board(9, EMPTY);

State get_state(const std::vector<char>& board) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] != EMPTY && board[i] == board[i + 1] && board[i] == board[i + 2]) {
            return WIN;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[i] != EMPTY && board[i] == board[i + 3] && board[i] == board[i + 6]) {
            return WIN;
        }
    }

    // Check diagonals
    if ((board[0] != EMPTY && board[0] == board[4] && board[0] == board[8]) ||
        (board[2] != EMPTY && board[2] == board[4] && board[2] == board[6])) {
        return WIN;
    }

    // Check for a draw
    bool hasEmptyCell = false;
    for (char cell : board) {
        if (cell == EMPTY) {
            hasEmptyCell = true;
            break;
        }
    }

    return hasEmptyCell ? ONGOING : DRAW;
}

bool is_valid_move(int move) {
    return move >= 0 && move < 9 && board[move] == EMPTY;
}

void make_move(int move, char player) {
    board[move] = player;
}

void undo_move(int move) {
    board[move] = EMPTY;
}

int minimax(bool isMaxTurn, char maximizerMark, char minimizerMark) {
    State state = get_state(board);

    if (state == WIN) {
        return maximizerMark == AI_SYMBOL ? 1 : -1;
    } else if (state == DRAW) {
        return 0;
    }

    int bestScore = isMaxTurn ? INT_MIN : INT_MAX;
    char currentPlayer = isMaxTurn ? AI_SYMBOL : PLAYER_SYMBOL;

    for (int i = 0; i < 9; ++i) {
        if (is_valid_move(i)) {
            make_move(i, currentPlayer);
            int score = minimax(!isMaxTurn, maximizerMark, minimizerMark);
            undo_move(i);

            if (isMaxTurn) {
                bestScore = std::max(bestScore, score);
            } else {
                bestScore = std::min(bestScore, score);
            }
        }
    }

    return bestScore;
}

int get_best_move(char player) {
    int bestScore = INT_MIN;
    int bestMove = -1;

    for (int i = 0; i < 9; ++i) {
        if (is_valid_move(i)) {
            make_move(i, player);
            int score = minimax(false, player, (player == AI_SYMBOL) ? PLAYER_SYMBOL : AI_SYMBOL);
            undo_move(i);

            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    return bestMove;
}

void print_board() {
    system("clear"); // Clear the terminal

    std::cout << "---------" << std::endl;
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            std::cout << std::endl;
        }
        std::cout << board[i] << " ";
    }
    std::cout << std::endl << "---------" << std::endl;
}

bool is_board_full() {
    for (char cell : board) {
        if (cell == EMPTY) {
            return false;
        }
    }
    return true;
}

int get_player_move() {
    int move;
    std::cout << "Enter your move (0-8): ";
    std::cin >> move;
    return move;
}

int main() {
    srand(time(NULL));

    while (true) {
        // Player's move
        print_board();
        int playerMove = get_player_move();
        while (!is_valid_move(playerMove)) {
            std::cout << "Invalid move. Try again: ";
            std::cin >> playerMove;
        }
        make_move(playerMove, PLAYER_SYMBOL);
        print_board();

        if (get_state(board) == WIN) {
            std::cout << "Congratulations! You won!" << std::endl;
            break;
        } else if (is_board_full()) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        // AI's move
        int aiMove = get_best_move(AI_SYMBOL);
        make_move(aiMove, AI_SYMBOL);
        print_board();
        std::cout << "AI's move: " << aiMove << std::endl;

        if (get_state(board) == WIN) {
            std::cout << "AI wins! Better luck next time." << std::endl;
            break;
        } else if (is_board_full()) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }
    }

    return 0;
}
