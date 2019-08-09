/*
** EPITECH PROJECT, 2018
** star to char
** File description:
** hangman
*/

#include "proto.h"
#include "define.h"

char *star_to_char(char *src, char *dest, char letter, int *tries)
{
	int i = 0;
	char *tmp = malloc(sizeof(dest));

	if (!tmp)
		exit(84);
	while (i < strlen(src)) {
		if (src[i] == letter) {
			tmp[i] = letter;
		} else {
			tmp[i] = dest[i];
		}
		i++;
	}
	if (strcmp(dest, tmp) == 0) {
		*tries -= 1;
		printf(BAD_LETTER, letter);
	}
	return (tmp);
}
