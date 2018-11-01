/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/
#include "gameboard.h"
#include "shared.h"
#include "utility.h"

#ifndef PLAYER_H
#define PLAYER_H
#define NAMELEN 20

struct player {
	char name[NAMELEN + 1];
	enum cell token;
	unsigned score;
};

BOOLEAN init_first_player(struct player *first, enum cell *token);
BOOLEAN init_second_player(struct player *second, enum cell token);
BOOLEAN make_move(struct player *player, game_board board);

#endif /* ifndef PLAYER_H */
