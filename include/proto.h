/*
** EPITECH PROJECT, 2018
** CPE_duostumper_7_2017
** File description:
** __DESCRIPTION__
*/

#ifndef	PROTO_H_
#define	PROTO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <time.h>
#include <dirent.h>

typedef struct game_s {
	int tries;
	char *word;
	char *find;
	char letter;
} game_t;

game_t init_game(char *file, int ac, char **av);
int game_loop(game_t game);
char *star_to_char(char *src, char *dest, char letter, int *tries);
int is_star_in_src(char *src);

#endif	/* PROTO_H_ */
