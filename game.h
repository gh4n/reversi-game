/***********************************************************************
 * Copyright © 2018 Joshua Jon. All rights reserved.
 **********************************************************************/
#include "gameboard.h"
#include "player.h"
#include "shared.h"

#ifndef GAME_H
#define GAME_H

struct player *play_game(struct player *first, struct player *second);
BOOLEAN apply_move(game_board board, unsigned y, unsigned x,enum cell player_token);
unsigned game_score(game_board board, enum cell player_token);
void swap_players(struct player **first, struct player **second);
struct player *get_winner(struct player *first, struct player *second);
#endif
