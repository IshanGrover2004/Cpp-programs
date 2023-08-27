#include <iostream>
#include <vector>
#include <climits>

enum State {
    ONGOING,
    DRAW,
    WIN
};

const char EMPTY = '-';
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
    std::cout << "---------" << std::endl;
    for (int i = 0; i < 9; ++i) {
        std::cout << "| " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            std::cout << "|" << std::endl;
            std::cout << "---------" << std::endl;
        }
    }
}

bool is_board_full() {
    for (char cell : board) {
        if (cell == EMPTY) {
            return false;
        }
    }
    return true;
}

bool is_game_over() {
    State state = get_state(board);
    return state == WIN || state == DRAW;
}

void make_player_move() {
    int move;
    do {
        std::cout << "Enter your move (0-8): ";
        std::cin >> move;
    } while (!is_valid_move(move));

    make_move(move, PLAYER_SYMBOL);
}

void make_ai_move() {
    int bestMove = get_best_move(AI_SYMBOL);
    make_move(bestMove, AI_SYMBOL);
}

void play_game() {
    std::cout << "Tic Tac Toe - AI vs Player" << std::endl;
    std::cout << "Player: " << PLAYER_SYMBOL << " AI: " << AI_SYMBOL << std::endl;
    std::cout << "Enter the position number to make a move." << std::endl;
    std::cout << "---------" << std::endl;
    print_board();
    std::cout << std::endl;

    while (!is_game_over()) {
        make_player_move();
        std::cout << std::endl;
        print_board();

        if (is_game_over()) {
            break;
        }

        make_ai_move();
        std::cout << std::endl;
        print_board();
    }

    State state = get_state(board);
    if (state == WIN) {
        std::cout << "Congratulations! You won!" << std::endl;
    } else if (state == DRAW) {
        std::cout << "It's a draw!" << std::endl;
    }
}

int main() {
    play_game();
    return 0;
}
