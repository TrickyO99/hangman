/*
** EPITECH PROJECT, 2018
** CPE_duostumper_7_2017
** File description:
** __DESCRIPTION__
*/

#include "proto.h"

static void check_errors(int ac, char **av)
{
	if (ac < 2 || access(av[1], F_OK) || opendir(av[1]) != NULL)
		exit(84);
}

int main(int ac, char **av)
{
	game_t game;

	check_errors(ac, av);
	game = init_game(av[1], ac, av);
	game_loop(game);
	return (0);
}
