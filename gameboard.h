/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/
#include "shared.h"
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#define COLUMN_WIDTH 4
#define BOARD_HEIGHT 8
#define BOARD_WIDTH BOARD_HEIGHT
#define CENTER_ROW_1 3
#define CENTER_ROW_2 4
#define CENTER_COLUMN_1 3
#define CENTER_COLUMN_2 4

struct player;
typedef enum cell game_board[BOARD_HEIGHT][BOARD_WIDTH];

void init_game_board(game_board board);
void display_board(game_board board, struct player *human, struct player *computer);
#endif
