###################################################
# Copyright © 2018 Joshua Jon. All rights reserved.
###################################################

SOURCES=game.c gameboard.c player.c reversi.c scoreboard.c \
utility.c

HEADERS=game.h gameboard.h player.h reversi.h scoreboard.h \
utility.h shared.h

OBJECTS=game.o gameboard.o player.o reversi.o scoreboard.o \
utility.o

MAKEFILE=Makefile

#variables
NAME = reversi
CC = gcc
CFLAGS = -Wall -ansi -pedantic

#link object files
all: $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

#compile the files
$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)

#clean object and exec file
clean:
	rm -f $(OBJECTS) $(NAME)
