/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/

#include "player.h"
#include "shared.h"
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#define MAX_SCORES 10
#define SCOREBOARD_INDENT 30

typedef struct player score;

void init_scoreboard(score scores[MAX_SCORES]);
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player *winner);
void display_scores(score scores[MAX_SCORES]);
#endif
