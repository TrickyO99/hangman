/*
** EPITECH PROJECT, 2018
** CPE_duostumper_7_2017
** File description:
** __DESCRIPTION__
*/

#include "proto.h"

static char **dic_parsing(char **lib, char *file)
{
	FILE *stream = fopen(file, "r");
	size_t len = 0;
	size_t i = 0;

	while (getline(&lib[i], &len, stream) != -1) {
		++i;
		lib[i] = malloc(sizeof(char) * 4096);
		if (lib[i] == NULL)
			exit(84);
	}
	return (lib);
}

static int number_of_word(char **lib)
{
	int i = 0;

	while (lib[i] != NULL) {
		++i;
	}
	return (i - 1);
}

game_t init_game(char *file, int ac, char **av)
{
	game_t game;
	struct stat sb;
	char **lib;

	stat(file, &sb);
	if (sb.st_size <= 0)
		exit(84);
	lib = malloc(sizeof(char *) * sb.st_size);
	if (lib == NULL)
		exit(84);
	dic_parsing(lib, file);
	srand(time(NULL));
	game.word = lib[rand() % number_of_word(lib)];
	if (ac == 3)
		game.tries = atoi(av[2]);
	else
		game.tries = 10;
	if (game.tries <= 0)
		exit(84);
	return (game);
}
