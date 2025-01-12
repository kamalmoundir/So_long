/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:31:34 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/11 15:53:49 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_array_map(t_game *game, int k)
{
	int	i;

	i = 0;
	while (game->map[i] && i < 1000)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	game->map = NULL;
	if (k == 1)
	{
		free(game);
		game = NULL;
	}
}

int	count_collectible(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

void	ft_inithelp(t_game *game, int j)
{
	game->x_mp = ft_strlen(game->map[0]);
	game->x = ft_strlen(game->map[0]);
	game->y_mp = j;
	game->y = j;
	game->points = count_collectible(game);
	game->points_way = 0;
	game->g_exit = 0;
	game->movment = 0;
}

void	init_game_data(t_game *game)
{
	int	j;
	int	i;

	j = -1;
	if (game->map[0] == NULL)
	{
		free_array_map(game, 1);
		ft_printf("Error\nDuplicate exit\n");
		exit(1);
	}
	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i])
		{
			if (game->map[j][i] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
		}
	}
	ft_inithelp(game, j);
}

int	initial(t_game *game, int file, char **copy)
{
	game->map = array_map(file);
	if (game->map == NULL)
		return (1);
	init_game_data(game);
	copy = copy_map(game->map, game->x);
	if (validate_path(game) != 1)
		return (free_array_map(game, 1), free_array(copy), 1);
	game->mlx = mlx_init();
	copy_mp(game->map, copy);
	if (game->mlx == NULL)
		return (1);
	game->mlx_win = mlx_new_window(game->mlx, game->x_mp * 64, game->y_mp * 64,
			"GALAXY WAR");
	load_image(game);
	put_img_map(game);
	return (0);
}
