/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/
#include "game.h"
#include "player.h"

BOOLEAN init_first_player(struct player *first, enum cell *token) {
	char name[NAMELEN + 1];

	printf("Please enter name of player 1: ");
	getString(name, NAMELEN);
	strncpy(first->name, name, NAMELEN);

	randomColor(token);
	first->token = *token;
	first->score = 0;

	return TRUE;
}

BOOLEAN init_second_player(struct player *second, enum cell token) {
	char name[NAMELEN + 1];

	printf("Please enter name of player 2: ");
	getString(name, NAMELEN);
	strncpy(second->name, name, NAMELEN);
	second->score = 0;
	/* Assign opposite token colour */
	if (token == RED) {
		second->token = BLUE;
	} else {
		second->token = RED;
	}

	return TRUE;
}

BOOLEAN make_move(struct player *first, game_board board) {
	BOOLEAN validCoord = FALSE;
	char coordinates[LINELEN], *token, *ptr;
	long x, y;

	printf("Please enter x and y coordinates separated by a comma for the "
	       "piece you wish to place:\n");

	while (validCoord == FALSE) {

		/* if EOF (ctrl-d) is input then quit to main menu*/
		if (getString(coordinates, LINELEN) == FALSE) {
			return FALSE;
		}
		/* if input is NULL then return to main menu */
		else if (coordinates[0] == '\0') {
			return FALSE;
		}

		if (coordinates[1] == ',') {

			token = strtok(coordinates, ",");
			y = strtol(token, &ptr, 10) - 1;

			token = strtok(NULL, ",");
			x = strtol(token, &ptr, 10) - 1;

			/* Check gameboard boundaries */
			if ((y >= 0 && y < BOARD_HEIGHT) && x >= 0 && x < BOARD_WIDTH) {
				if ((apply_move(board, x, y, first->token)) == TRUE) {
					validCoord = TRUE;
				} else {
					printf("There are no valid pieces to capture using these "
					       "coordinates. Please try again: \n");
				}
			} else {
				printf("Coordinates exceed boundaries of the gameboard. "
				       "Please try again: \n");
			}
		} else {
			printf("The input coordinates do not match the required format.\n"
			       "Please enter x and y coordinates separated by a comma "
			       "for the piece you wish to place: \n");
		}
	}

	return TRUE;
}
