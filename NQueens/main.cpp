
#define BOARD_SIZE 2

#include <iostream>
#include <cassert>
#include "NQueen.h"

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    memset(board, '_', sizeof(board));

    bool solution_exists = n_queens(board);

    if(solution_exists)
        print_board(board);
    else
        std::cout << "nada, no solution!\n";
    return 0;
}