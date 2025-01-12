/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_validate_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:22:46 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/11 15:44:22 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validate_extention(char *s)
{
	char	*tmp;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(s, '/');
	while (str[i])
	{
		i++;
	}
	--i;
	if (!str[i])
		return (0);
	if (ft_strlen(str[i]) == 4)
		return (free_array(str), printf("Error\nBad extension\n"), 0);
	if (ft_strncmp(str[1], ".ber", 4) == 0)
		return (free_array(str), printf("Error\nBad extension\n"), 0);
	tmp = ft_strnstr(str[i], ".ber", ft_strlen(str[i]));
	if (tmp == NULL || *tmp == '\0' || *(tmp + 4) != '\0')
		return (free_array(str), printf("Error\nBad extension\n"), 0);
	return (free_array(str), 1);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**copy_map(char **map, int rows)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	path_finder(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'E')
		g->g_exit++;
	if (x < 0 || x >= g->x_mp || y < 0 || y >= g->y_mp || g->map[y][x] == 'E'
		|| g->map[y][x] == '1' || g->map[y][x] == 'V')
		return ;
	if (g->map[y][x] == 'C')
		g->points_way++;
	g->map[y][x] = 'V';
	path_finder(g, x + 1, y);
	path_finder(g, x - 1, y);
	path_finder(g, x, y + 1);
	path_finder(g, x, y - 1);
}

int	validate_path(t_game *g)
{
	if (!g)
		return (-1);
	if (!validate_caract(g))
		return (-1);
	g->y = 0;
	while (g->y < g->y_mp)
	{
		g->x = 0;
		while (g->x < g->x_mp)
		{
			if (g->map[g->y][g->x] == 'P')
			{
				path_finder(g, g->x, g->y);
				if (g->points == g->points_way && g->g_exit)
					return (g->y = 0, g->x = 0, 1);
				else
					return (printf("Error\nNo valid road\n") - 1);
			}
			g->x++;
		}
		g->y++;
	}
	return (0);
}
