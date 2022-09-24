/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:29:57 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/24 21:38:13 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		guard_free_map(&game->parsing.map);
	if (key == KEY_W)
		game->active_keys.w = 1;
	if (key == KEY_A)
		game->active_keys.a = 1;
	if (key == KEY_S)
		game->active_keys.s = 1;
	if (key == KEY_D)
		game->active_keys.d = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == KEY_W)
		game->active_keys.w = 0;
	if (key == KEY_A)
		game->active_keys.a = 0;
	if (key == KEY_S)
		game->active_keys.s = 0;
	if (key == KEY_D)
		game->active_keys.d = 0;
	return (0);
}

// int	free_and_close(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (game->parsing.map[i])
// 		free(game->parsing.map[i++]);
// 	free(game->parsing.map);
// 	exit(0);
// 	return (0);
// }

int	move(t_game *game)
{
	if (game->active_keys.w && !game->active_keys.s)
		move_up(game);
	if (game->active_keys.a && !game->active_keys.d)
		move_left(game);
	if (game->active_keys.s && !game->active_keys.w)
		move_down(game);
	if (game->active_keys.d && !game->active_keys.a)
		move_right(game);
	return (0);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	get_img(&game->img, game->mlx);
	game->win = mlx_new_window(game->mlx, ((int)game->parsing.s_len * 50),
			(game->parsing.s_count * 50), "so_long");
	mlx_hook(game->win, 2, 1L << 2, key_press, game);
	mlx_hook(game->win, 3, 1L << 3, key_release, game);
	mlx_key_hook(game->win, move, game);
	mlx_loop_hook(game->mlx, rendering, game);
	mlx_hook(game->win, 17, 1L << 0, guard_free_map, &game->parsing.map);
	printf("%d\n", __LINE__);
	mlx_loop(game->mlx);
}
