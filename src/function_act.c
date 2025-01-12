/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_act.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:34:05 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/11 15:45:25 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	go_up(t_game *game)
{
	if (game->player_x > 1 && game->map[game->player_x
			- 1][game->player_y] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor,
			game->player_y * 64, game->player_x * 64);
		game->player_x -= 1;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_player_up,
			game->player_y * 64, game->player_x * 64);
		ft_printf("movment :%d\n", ++game->movment);
	}
}

void	go_down(t_game *game)
{
	if (game->player_x < game->y_mp - 2 && game->map[game->player_x
			+ 1][game->player_y] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor,
			game->player_y * 64, game->player_x * 64);
		game->player_x += 1;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_player_down,
			game->player_y * 64, game->player_x * 64);
		ft_printf("movment :%d\n", ++game->movment);
	}
}

void	go_left(t_game *game)
{
	if (game->player_y > 1 && game->map[game->player_x][game->player_y
		- 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor,
			game->player_y * 64, game->player_x * 64);
		game->player_y -= 1;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_player_left,
			game->player_y * 64, game->player_x * 64);
		ft_printf("movment :%d\n", ++game->movment);
	}
}

void	go_right(t_game *game)
{
	if ((game->player_y + 1) < (game->x_mp - 1)
		&& game->map[game->player_x][game->player_y + 1] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor,
			game->player_y * 64, game->player_x * 64);
		game->player_y += 1;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_player_right, game->player_y * 64, game->player_x * 64);
		ft_printf("movment :%d\n", ++game->movment);
	}
}
