/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/

#include "reversi.h"

int main(void) {
	score scrboard[MAX_SCORES];
	struct player first, second, *winner = NULL;
	BOOLEAN menuLoop = TRUE;
	int result = 0;
	int min = 1, max = 3;

	init_scoreboard(scrboard);

	while (menuLoop == TRUE) {
		printf("Welcome to Reversi!\n");
		printf("===================\n");
		printf("Select an option:\n");
		printf("1. Play a game\n");
		printf("2. Display High Scores\n");
		printf("3. Quit the program\n");
		printf("Please enter your choice\n");

		getInteger(&result, LINELEN, min, max);

		if (result == 1) {
			winner = play_game(&first, &second);
			add_to_scoreboard(scrboard, winner);
		} else if (result == 2) {
			display_scores(scrboard);
		} else {
			menuLoop = FALSE;
		}
	}

	return EXIT_SUCCESS;
}
