/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/
#include "gameboard.h"
#include "player.h"

void init_game_board(game_board board) {
	int i;
	int j;

	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			/* Player 1 starting squares to RED, Player 2 BLUE */
			if ((i == CENTER_ROW_1 && j == CENTER_COLUMN_1) ||
			    (i == CENTER_ROW_2 && j == CENTER_COLUMN_2)) {
				board[i][j] = RED;
			} else if ((i == CENTER_ROW_1 && j == CENTER_COLUMN_2) ||
			           (i == CENTER_ROW_2 && j == CENTER_COLUMN_1)) {
				board[i][j] = BLUE;
			} else {
				board[i][j] = BLANK;
			}
		}
	}
}

void display_board(game_board board, struct player *first,
                   struct player *second) {
	int i;
	int j;
	print_divider(LONG, THICK);

	if (first->token == RED) {
		printf("Player One's Details\n");
		print_divider(SHORT, THIN);
		printf("Name: %s" INDENT "Score: %d" INDENT "Token Color: " COLOR_RED
		       "0" COLOR_RESET "\n", first->name, first->score);
		print_divider(LONG, THIN);

		printf("Player Two's Details\n");
		print_divider(SHORT, THIN);
		printf("Name: %s" INDENT "Score: %d" INDENT "Token Color: " COLOR_BLUE
		       "0" COLOR_RESET "\n", second->name, second->score);
	} else {
		printf("Player One's Details\n");
		print_divider(SHORT, THIN);
		printf("Name: %s" INDENT "Score: %d" INDENT "Token Color: " COLOR_BLUE
		       "0" COLOR_RESET "\n", first->name, first->score);
		print_divider(LONG, THIN);

		printf("Player Two's Details\n");
		print_divider(SHORT, THIN);
		printf("Name: %s" INDENT "Score: %d" INDENT "Token Color: " COLOR_RED
		       "0" COLOR_RESET "\n", second->name, second->score);
	}

	print_divider(LONG, THIN);

	/* Display numbers on top of board */
	for (i = 0; i <= BOARD_WIDTH; i++) {
		if (i == 0) {
			printf(INDENT);
		} else {
			printf(" %d  ", i);
		}
	}

	printf("\n");
	print_divider(MED, THICK);

	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			if (j == 0) {
				printf(" %d |", i + 1);
			}

			if (board[i][j] == RED) {
				printf(" " COLOR_RED "0" COLOR_RESET " |");
			} else if (board[i][j] == BLUE) {
				printf(" " COLOR_BLUE "0" COLOR_RESET " |");
			} else {
				printf(" " COLOR_RESET "0" COLOR_RESET " |");
			}

			if (j == BOARD_WIDTH - 1) {
				printf("\n");
				print_divider(MED, THIN);
			}
		}
	}
	print_divider(MED, THICK);
}
