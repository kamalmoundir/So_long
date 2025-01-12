/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:16:45 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/11 15:44:55 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validate_size_map(char **map)
{
	size_t	i;
	size_t	size_line;

	i = 1;
	if (map == NULL || map[0] == NULL)
		return (0);
	size_line = ft_strlen(map[0]);
	while (map[i])
	{
		if (size_line != (ft_strlen(map[i])))
		{
			return (printf("Error\nNo rectangular\n"), 0);
		}
		i++;
	}
	if (i == size_line)
		return (1);
	return (1);
}

int	validate_map_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' || map[i][0] != '1')
				return (printf("Error\nNot surrounded by walls\n"), 0);
			if (map[i][ft_strlen(map[i]) - 1] != '1')
				return (printf("Error\nNot surrounded by walls\n"), 0);
			j++;
		}
		i++;
	}
	i--;
	j = 0;
	while (map[i][j])
		if (map[i][j++] != '1')
			return (printf("Error\nNot surrounded by walls\n"), 0);
	return (1);
}

int	validate_limited_caracters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (!game || !game->map)
		return (0);
	if (!validate_map_wall(game->map) || !validate_size_map(game->map))
		return (0);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'P')
				return (printf("Error\nWrong characters\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

void	vald_dup_ext_carct(char **map, int *E, int *C, int *P)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				(*E)++;
			else if (map[i][j] == 'P')
				(*P)++;
			else if (map[i][j] == 'C')
				(*C)++;
			j++;
		}
		i++;
	}
}

int	validate_caract(t_game *game)
{
	int	e;
	int	c;
	int	p;

	e = 0;
	p = 0;
	c = 0;
	if (!validate_limited_caracters(game) || !validate_map_wall(game->map)
		|| !validate_size_map(game->map))
		return (0);
	vald_dup_ext_carct(game->map, &e, &c, &p);
	if (e == 0)
		return (printf("Error\nNo exit\n"), 0);
	if (e > 1)
		return (printf("Error\nDuplicate exit\n"), 0);
	if (p == 0)
		return (printf("Error\nNo player\n"), 0);
	if (p > 1)
		return (printf("Error\nDuplicate player\n"), 0);
	if (c == 0)
		return (printf("Error\nNo collectible\n"), 0);
	return (1);
}

/*
int	main(void)
{
	t_game	*game;
	int		i;
	int		file;

	i = 0;
	game = malloc(sizeof(t_game));
	if (!game)
	{
		perror("Error: Failed to allocate memory for game");
		return (1);
	}
	file = open("mapa/test.ber", O_RDONLY);
	game->map = array_map(file);
	game->x_mp = 13;
	game->y_mp = 5;
	game->points =1;
	if (game->map == NULL)
	{
		perror("error");
		return (1);
	}
	ft_printf("size ok=%d\n", validate_size_map(game->map));
	//ft_printf("wall ok=%d\n", validate_map_wall(game->map));
	ft_printf("caracetres ok=%d\n", validate_limited_caracters(game));
	ft_printf("caracter ok=%d\n", validate_caract(game));
	ft_printf("validate path %d\n",validate_path(game));
	while (game->map[i])
	{
		// ft_printf("%s\n", map[i]);
		free(game->map[i]);
		i++;
	}
	free(game->map[i]);
	free(game->map);
	free(game);
	return (0);
}

*/