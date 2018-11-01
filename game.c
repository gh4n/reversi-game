/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/
#include "game.h"

struct player *play_game(struct player *first, struct player *second) {
	game_board board;
	BOOLEAN quit = FALSE;
	enum cell token;
	struct player *current, *other;

	init_game_board(board);
	init_first_player(first, &token);
	init_second_player(second, token);

	/* Initial player is the player whose token is RED */
	if (token == RED) {
		current = first;
		other = second;
	} else {
		current = second;
		other = first;
	}

	/* Game loop */
	while (quit == FALSE) {
		display_board(board, first, second);
		printf("It is %s's turn \n", current->name);
		/* quit loop if make_move returns false */
		if (make_move(current, board) == FALSE) {
			quit = TRUE;
		}
		/* Update scores */
		current->score = game_score(board, current->token);
		other->score = game_score(board, other->token);

		swap_players(&current, &other);
	}

	return get_winner(first, second);
}

BOOLEAN apply_move(game_board board, unsigned y, unsigned x, enum cell player_token) {
	unsigned captured_pieces = 0;
	int currentRow, currentCol, row, col;

	/* loop 2d array of 8 squares surrounding the starting tokens */
	for (row = -1; row < 2; row++) {
		for (col = -1; col < 2; col++) {
			/* skip the original x,y coordinate */
			if (row != 0 || col != 0) {
				/* increment */
				currentCol = x + col;
				currentRow = y + row;

				/* If the current square contains an enemy token */
				if (board[currentRow][currentCol] != player_token &&
				    board[currentRow][currentCol] != BLANK &&
				    (currentRow > 0 && currentRow < BOARD_HEIGHT && currentCol > 0 &&
				     currentCol < BOARD_WIDTH)) {
					/* Increment until a token is found adjacent with enemy token(s) */
					while (board[currentRow][currentCol] != player_token &&
					       board[currentRow][currentCol] != BLANK &&
					       (currentRow > 0 && currentRow < BOARD_HEIGHT &&
					        currentCol > 0 && currentCol < BOARD_WIDTH)) {

						currentRow = currentRow + row;
						currentCol = currentCol + col;
					}
					/* if current player token is found successfully */
					if (board[currentRow][currentCol] == player_token) {
						/* insert player token into the coordinate */
						board[y][x] = player_token;

						/* increment backwards and capture each enemy token*/
						while (currentRow != y || currentCol != x) {
							currentRow = currentRow - row;
							currentCol = currentCol - col;
							board[currentRow][currentCol] = player_token;
							captured_pieces++;
						}
					}
				}
			}
		}
	}

	/* Check if the move was valid */
	if (captured_pieces > 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

unsigned game_score(game_board board, enum cell player_token) {
	unsigned int temp = 0;
	int i;
	int j;

	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			/* increment score each time player_token is located */
			if (board[i][j] == player_token) {
				temp++;
			}
		}
	}
	return temp;
}

void swap_players(struct player **first, struct player **second) {
	struct player *temp = *first;
	*first = *second;
	*second = temp;
}

struct player *get_winner(struct player *first, struct player *second) {
	if (first->score > second->score) {
		return first;
	} else {
		return second;
	}
}
