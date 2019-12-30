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

#ifndef BOARD_SIZE
    #error "BOARD_SIZE needs to be defined"
#endif

#ifdef BOARD_SIZE

static_assert(BOARD_SIZE > 0, "wtf u doin?");

static bool _legal(char board[BOARD_SIZE][BOARD_SIZE], unsigned int row, unsigned int col)
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
        if(board[r][col] == 'Q')
            return false;
    }
    // check major diag
    int offset = std::min(row, col);
    for(int x = 1; x <= offset;++x)
    {
        if(board[row - x][col - x] == 'Q')
            return false;
    }
    // check minor diag
    offset = std::min(row, BOARD_SIZE - col - 1);
    for(int x = 1; x <= offset;++x)
    {
        if(board[row - x][col + x] == 'Q')
            return false;
    }
    return true;
}

static bool _n_queens(char board[BOARD_SIZE][BOARD_SIZE], int exclude_row)
{
    if(exclude_row >= BOARD_SIZE)
        return true;

    for(unsigned int c = 0;c < BOARD_SIZE;++c)
    {
        board[exclude_row][c] = 'Q';
        if(_legal(board, exclude_row, c))
        {
            bool solution_exists = _n_queens(board, exclude_row + 1);
            if(!solution_exists)
                board[exclude_row][c] = '_';
            else
                return true;
        }
        else
        {
            board[exclude_row][c] = '_';
        }
    }
    return false;
}

bool n_queens(char board[BOARD_SIZE][BOARD_SIZE])
{
    return _n_queens(board, 0);
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    for(unsigned int i = 0;i < BOARD_SIZE;++i)
    {
        for(unsigned int j = 0;j < BOARD_SIZE;++j)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}
#endif