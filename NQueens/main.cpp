#include <iostream>
#include <cassert>
#include "NQueen.h"

int main()
{
    unsigned int size = 5;
    char* board = (char*) malloc(size * sizeof(char));
    memset(board, '_', size * size * sizeof(char));

    bool solution_exists = n_queens(board, size);

    if(solution_exists)
        print_board(board, size);
    else
        std::cout << "nada, no solution!\n";
    return 0;
}