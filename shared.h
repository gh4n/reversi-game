/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef SHARED_H
#define SHARED_H
#define COLOR_RED "\33[31m"
#define COLOR_BLUE "\33[34m"
#define COLOR_RESET "\33[0m"
#define NUM_COLORS 2
typedef enum { FALSE, TRUE } BOOLEAN;
enum cell { BLANK, RED, BLUE };
enum length { SHORT = 20, MED = 36, LONG = 80 };
enum thickness { THIN, THICK };

#endif
