/*
** EPITECH PROJECT, 2018
** CPE_duostumper_7_2017
** File description:
** __DESCRIPTION__
*/

#include "proto.h"
#include "define.h"

static char *init_find_word(char *word)
{
	int i = 0;
	char *find = malloc(sizeof(char) * strlen(word));

	if (find == NULL)
		exit(84);
	while (i < strlen(word) - 1) {
		find[i] = '*';
		++i;
	}
	find[i] = '\0';
	return (find);
}

static char get_letter(void)
{
	char c;

	c = getchar();

	if (c == EOF)
		exit(0);
	else if (c <= 32)
		c = get_letter();
	return (c);
}

int game_loop(game_t game)
{
	game.find = init_find_word(game.word);
	while (game.tries > 0 && is_star_in_src(game.find) != 0) {
		printf("%s\n", game.find);
		printf(TRIES, game.tries);
		printf(LETTER);
		game.letter = get_letter();
		game.find = star_to_char(game.word, game.find, game.letter,
		&game.tries);
	}
	printf("%s\n", game.find);
	printf(TRIES, game.tries);
	if (game.tries <= 0)
		printf(LOOSE);
	else
		printf(VICTORY);
	free(game.word);
	free(game.find);
	return (0);
}
