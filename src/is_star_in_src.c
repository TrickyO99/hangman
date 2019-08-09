/*
** EPITECH PROJECT, 2018
** star in src
** File description:
** is star
*/

#include "proto.h"

int	is_star_in_src(char *src)
{
	int i = 0;

	while (src[i] != '\0') {
		if (src[i] == '*') {
			return (1);
		}
		i++;
	}
	return (0);
}