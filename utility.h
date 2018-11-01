/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/
#include "gameboard.h"
#include "shared.h"
#include <limits.h>

#ifndef UTILITY_H
#define UTILITY_H
#define LINELEN 80
#define EXTRACHARS 2
#define NEWLINE '\n'
#define INDENT "    "
#define DIVIDER_THIN "-"
#define DIVIDER_THICK "="

void read_rest_of_line(void);
void print_divider(enum length length, enum thickness thickness);
BOOLEAN getString(char *output_string, const unsigned length);
void getInteger(int *, const unsigned, const int, const int);
void randomColor(enum cell *tokenColour);

#endif
