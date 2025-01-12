/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:10:23 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/11 15:48:15 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_mlx_help(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 0, (int (*)())close_window, game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		file;
	char	**copy;

	file = 0;
	copy = NULL;
	if (ac == 2)
	{
		file = open(av[1], O_RDONLY);
		if (file < 0)
			return (printf("Error\nNo exist map\n"), 1);
		if (validate_extention(av[1]) == 0)
			return (1);
		game = malloc(sizeof(t_game));
		if (!game)
			return (ft_printf("Error1\n"), 1);
		if (initial(game, file, copy) == 0)
			ft_mlx_help(game);
	}
	else
		return (ft_printf("Error\nWrong number of arguments\n"), 1);
	return (0);
}
