/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:48:37 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/10 20:15:58 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player_up)
		mlx_destroy_image(game->mlx, game->img_player_up);
	if (game->img_player_down)
		mlx_destroy_image(game->mlx, game->img_player_down);
	if (game->img_player_right)
		mlx_destroy_image(game->mlx, game->img_player_right);
	if (game->img_player_left)
		mlx_destroy_image(game->mlx, game->img_player_left);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_array_map(game, 0);
	free(game);
	ft_printf("Window closed !\n");
	exit(0);
}

int	close_window_esc(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_printf("ESC pressed !\n");
		close_window(game);
		exit(0);
	}
	return (0);
}

void	copy_mp(char **dest, char **src)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return ;
	while (src[i])
	{
		ft_strlcpy(dest[i], src[i], ft_strlen(src[i]) + 1);
		free(src[i]);
		i++;
	}
	free(src);
	dest[i] = NULL;
}

/*
int	main(void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if(!game)
	{
		perror("error");
		return (1);
	}
	game->mlx=mlx_init();
	if(game->mlx == NULL)
	{
		return (1);
	}
	game->mlx_win = mlx_new_window(game->mlx, 500, 500, "test");
	mlx_hook(game->mlx_win, 17, 0, (int (*)())close_window, game);
	mlx_hook(game->mlx_win, 4, 0,(int (*)())resize_window,game);
		mlx_key_hook(game->mlx_win, close_window_esc , game);

	mlx_loop(game->mlx);
	free(game->mlx);
	free(game->mlx_win);
	free(game);
	return (0);
}*/