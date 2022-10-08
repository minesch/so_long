/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:29:57 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/25 19:03:53 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	input(int key, t_game *game)
{
	char	*step;

	if (key == KEY_ESC)
		guard_free_map(&game->parsing.map);
	if (key == KEY_W)
		move_up(game);
	if (key == KEY_A)
		move_left(game);
	if (key == KEY_S)
		move_down(game);
	if (key == KEY_D)
		move_right(game);
	game->count++;
	step = ft_itoa(game->count);
	write(1, step, ft_strlen(step));
	free(step);
	write(1, "\n", 1);
	return (0);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	get_img(&game->img, game->mlx);
	game->win = mlx_new_window(game->mlx, ((int)game->parsing.s_len * 50),
			(game->parsing.s_count * 55), "so_long");
	mlx_hook(game->win, 2, 1L << 2, input, game);
	mlx_loop_hook(game->mlx, rendering, game);
	mlx_hook(game->win, 17, 1L << 0, guard_free_map, &game->parsing.map);
	mlx_loop(game->mlx);
}
