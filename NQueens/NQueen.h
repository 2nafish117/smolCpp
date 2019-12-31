#pragma once
/*
    exampe board
[
    [0, Q, 0, 0],
    [0, 0, 0, Q],
    [Q, 0, 0, 0],
    [0, 0, Q, 0]

    [Q, 0, 0, 0],
    [0, 0, Q, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0]
]
*/

#include <iostream>
#include <cstring>
#include <algorithm>

static bool _legal(char* board, unsigned int size, unsigned int row, unsigned int col)
{
    // checking rows is redundant
    // check rows
    // for(unsigned int c = 0;c < col;++c)
    // {
    //     if(board[row][c] == 'Q')
    //         return false;
    // }
    // check columns
    for(unsigned int r = 0;r < row;++r)
    {
        if(board[r * size + col] == 'Q')
            return false;
    }
    // check major diag
    int offset = std::min(row, col);
    for(int x = 1; x <= offset;++x)
    {
        if(board[(row - x) * size + col - x] == 'Q')
            return false;
    }
    // check minor diag
    offset = std::min(row, size - col - 1);
    for(int x = 1; x <= offset;++x)
    {
        if(board[(row - x) * size + col + x] == 'Q')
            return false;
    }
    return true;
}

static bool _n_queens(char* board, unsigned int size, int exclude_row)
{
    if(exclude_row >= size)
        return true;

    for(unsigned int c = 0;c < size;++c)
    {
        board[exclude_row * size + c] = 'Q';
        if(_legal(board, size, exclude_row, c))
        {
            bool solution_exists = _n_queens(board, size, exclude_row + 1);
            if(!solution_exists)
                board[exclude_row * size + c] = '_';
            else
                return true;
        }
        else
        {
            board[exclude_row * size + c] = '_';
        }
    }
    return false;
}

bool n_queens(char* board, unsigned int size)
{
    assert(size > 0 && "size needs to be positive BRUH");
    return _n_queens(board, size, 0);
}

void print_board(char* board, unsigned int size)
{
    for(unsigned int i = 0;i < size;++i)
    {
        for(unsigned int j = 0;j < size;++j)
        {
            std::cout << board[i * size + j] << " ";
        }
        std::cout << "\n";
    }
}