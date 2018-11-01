/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/

#include "scoreboard.h"

void init_scoreboard(score scores[MAX_SCORES]) {
	int i;

	for (i = 0; i < MAX_SCORES; i++) {
		scores[i].score = 0;
	}
}

BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player *winner) {
	int i;
	int j;

	for (i = 0; i < MAX_SCORES; i++) {
		if (winner->score > scores[i].score) {
			for (j = MAX_SCORES - 1; j >= i; --j) {
				scores[j] = scores[j - 1];
			}

			scores[i].score = winner->score;
			strcpy(scores[i].name, winner->name);

			return TRUE;
		}
	}
	return FALSE;
}

void display_scores(score scores[MAX_SCORES]) {
	int i;
	int j;
	long nameLen;

	printf("Reversi - Top Scores\n");
	print_divider(SHORT, THICK);
	print_divider(MED, THIN);
	printf("Name                         | Score\n");
	print_divider(MED, THIN);

	for (i = 0; i < MAX_SCORES; i++) {
		if (scores[i].score != 0) {
			nameLen = strlen(scores[i].name);
			printf("%s", scores[i].name);

			for (j = SCOREBOARD_INDENT; j > nameLen; j--) {
				printf(" ");
			}

			printf("| %u\n", scores[i].score);
		}
	}
	print_divider(MED, THIN);
}
