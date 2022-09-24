/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:29:35 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/24 19:10:06 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "keys.h"
# include "get_next_line.h"

# define COIN_PATH "./img/coin.xpm"
# define PLAYER_PATH "./img/player.xpm"
# define WALL_PATH  "./img/wall.xpm"
# define BACKGROUND_PATH "./img/background.xpm"
# define EXIT_PATH "./img/exit.xpm"

typedef struct s_key_active	t_key_active;
typedef struct s_img		t_img;
typedef struct s_game		t_game;
typedef struct s_parsing	t_parsing;
typedef struct s_position	t_position;

struct s_position
{
	int	x;
	int	y;
};

struct s_parsing
{
	char		**map;
	int			coin;
	int			exit;
	int			player;
	int			s_count;
	size_t		s_len;
	size_t		i;
	size_t		j;
	t_position	pos;
};

struct s_key_active
{
	int	w;
	int	a;
	int	s;
	int	d;
};

struct s_img
{
	void	*coin;
	void	*player;
	void	*wall;
	void	*bg;
	void	*exit;
};

struct s_game
{
	int				coin;
	int				count;
	void			*mlx;
	void			*player;
	void			*win;
	t_parsing		parsing;
	t_key_active	active_keys;
	t_img			img;
};

char	**map_matrix(int s_count, int fd);
int		valid_name(char *str);
int		string_count(char *path);

void	validation(t_parsing *sl, int fd, char *str);
int		guard_free_map(char ***map);
void	check_slen(t_parsing *sl);
void	check_wall(t_parsing *sl);
void	error(t_parsing *sl, int indicate);
void	check_top_bottom(t_parsing *sl);
void	check_right_left(t_parsing *sl);
void	check_components(t_parsing *sl);

int		get_coin(char **map);

int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
// int		free_and_close(t_game *game);
int		rendering(t_game *game);
void	start_game(t_game *game);

void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);

void	get_img(t_img *img, void *mlx);
int		rgb(int r, int g, int b);
int		rendering(t_game *game);
void	render(t_game *game);
void	render_img(int *arr, t_game *game);
char	*ft_itoa(int n);

#endif
