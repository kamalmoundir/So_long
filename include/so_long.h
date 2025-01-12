/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:55:50 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/10 22:34:33 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/ft_printf/ft_printf.h"
# include "../library/libft/libft.h"
# include "../library/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gamer
{
	int		p_x;
	int		p_y;

}			t_gamer;

typedef struct s_game
{
	char	**map;
	int		x_mp;
	int		y_mp;
	int		x;
	int		y;
	int		g_exit;
	int		points;
	int		points_way;

	void	*mlx;
	void	*mlx_win;

	void	*img_wall;
	void	*img_collectible;

	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_left;
	void	*img_player_right;

	void	*img_floor;
	void	*img_exit;

	int		player_x;
	int		player_y;

	int		movment;

}			t_game;

char		*get_next_line(int fd);
size_t		ft_strlcpy_gnl(char *dst, char *src, size_t size);
size_t		ft_strlcat_gnl(char *dst, char *src, size_t size);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_get_line(int fd, char *line);
int			close_window_esc(int keycode, t_game *game);
int			close_window(t_game *game);
char		**array_map(int fd);
int			validate_path(t_game *g);
char		**array_map(int fd);
void		free_array_map(t_game *game, int k);
int			put_img_map(t_game *game);
int			load_image(t_game *game);
char		**copy_map(char **map, int rows);
int			key_hook(int keycode, t_game *game);
void		go_right(t_game *game);
void		go_left(t_game *game);
void		go_down(t_game *game);
void		go_up(t_game *game);
void		init_game_data(t_game *game);
void		reach_exit(t_game *game);
void		count_c(t_game *game);
void		copy_mp(char **dest, char **src);
void		free_array(char **str);
int			initial(t_game *game, int file, char **copy);
void		put_images_win(t_game *game, int i, int j);
int			validate_extention(char *s);
int			validate_caract(t_game *game);

#endif
