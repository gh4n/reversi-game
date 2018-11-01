/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/

#include "utility.h"

void read_rest_of_line(void) {
	int ch;
	while (ch = getc(stdin), ch != EOF && ch != NEWLINE)
		;
	clearerr(stdin);
}

void print_divider(enum length divLength, enum thickness divThickness) {
	int i;

	for (i = 0; i < divLength; i++) {
		if (divThickness == THIN) {
			printf(DIVIDER_THIN);
		} else {
			printf(DIVIDER_THICK);
		}
	}
	printf("\n");
}

BOOLEAN getString(char *output_string, const unsigned length) {
	int finished = FALSE;
	char inputString[LINELEN + EXTRACHARS];

	do {
		if (fgets(inputString, length + EXTRACHARS, stdin) == NULL) {
			read_rest_of_line();
			return FALSE;
		} else if (inputString[strlen(inputString) - 1] != '\n') {
			printf("Input was too long.\n");
			/*clear the buffer */
			read_rest_of_line();
		} else {
			finished = TRUE;
		}

	} while (finished == FALSE);

	inputString[strlen(inputString) - 1] = '\0';
	strcpy(output_string, inputString);

	return TRUE;
}

void getInteger(int *integer, const unsigned length, const int min,
                const int max) {
	int finished = FALSE;
	char output[LINELEN + EXTRACHARS];
	int int_result = 0;

	do {
		fgets(output, length + EXTRACHARS, stdin);

		if (output[strlen(output) - 1] != '\n') {
			printf("Input was too long. Please try again\n");
			read_rest_of_line();
		} else {
			output[strlen(output) - 1] = '\0';
			int_result = atoi(output);

			if (int_result < min || int_result > max || strlen(output) > 2) {
				printf("Input was not in range 1-3. Please try again \n");
			} else {
				finished = TRUE;
			}
		}
	} while (finished == FALSE);

	*integer = int_result;
}

void randomColor(enum cell *tokenColour) {
	int randomNumber;
	srand(time(NULL));
	randomNumber = rand() % NUM_COLORS + 1;

	if (randomNumber == 1) {
		*tokenColour = RED;
	} else {
		*tokenColour = BLUE;
	}
}
