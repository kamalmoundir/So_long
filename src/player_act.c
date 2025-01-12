/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_act.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:30:41 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/10 20:15:26 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (keycode == 119 || keycode == 65362)
		go_up(game);
	if (keycode == 115 || keycode == 65364)
		go_down(game);
	if (keycode == 97 || keycode == 65361)
		go_left(game);
	if (keycode == 100 || keycode == 65363)
		go_right(game);
	count_c(game);
	reach_exit(game);
	return (0);
}

void	reach_exit(t_game *game)
{
	if (game->map[game->player_x][game->player_y] == 'E')
	{
		if (game->points != 0)
			ft_printf("\nGAME OVER  faltan %d colectibles!\n", game->points);
		else
			ft_printf("\nYOU WIN !\n");
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_exit,
			game->player_y * 64, game->player_x * 64);
		close_window(game);
	}
}

void	count_c(t_game *game)
{
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		game->points--;
		game->map[game->player_x][game->player_y] = '0';
	}
}
/*
int	wait_and_close(t_game *game)
{
	static clock_t	start_time = 0;

	if (start_time == 0)
	{
		start_time = clock(); // Inicializa el tiempo
		mlx_clear_window(game->mlx, game->mlx_win);
		mlx_string_put(game->mlx, game->mlx_win, 100, 100, 0xFFFFFF,
			"You Win!");
	}
	// Espera 2 segundos antes de cerrar la ventana
	if ((clock() - start_time) / CLOCKS_PER_SEC > 4)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0); // Cierra el programa
	}
	return (0); // Mantener el loop activo
}
*/
