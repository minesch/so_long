/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:38:21 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/24 19:06:26 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	move_left(t_game *game)
{
	t_position	pl_pos;

	pl_pos = game->parsing.pos;
	if (game->parsing.map[pl_pos.y][pl_pos.x - 1] == '0')
	{
		swap(&game->parsing.map[pl_pos.y][pl_pos.x],
			&game->parsing.map[pl_pos.y][pl_pos.x - 1]);
	}
	else if (game->parsing.map[pl_pos.y][pl_pos.x - 1] == 'C')
	{
		game->parsing.coin--;
		game->parsing.map[pl_pos.y][pl_pos.x - 1] = 'P';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
	else if (game->parsing.map[pl_pos.y][pl_pos.x - 1] == 'E'
		&& !game->parsing.coin)
		guard_free_map(&game->parsing.map);
	else if (game->parsing.map[pl_pos.y][pl_pos.x - 1]
			== 'E' && game->parsing.coin != 0)
	{
		game->parsing.map[pl_pos.y][pl_pos.x - 1] = 'Q';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
}

void	move_down(t_game *game)
{
	t_position	pl_pos;

	pl_pos = game->parsing.pos;
	if (game->parsing.map[pl_pos.y + 1][pl_pos.x] == '0')
	{
		swap(&game->parsing.map[pl_pos.y][pl_pos.x],
			&game->parsing.map[pl_pos.y + 1][pl_pos.x]);
	}
	else if (game->parsing.map[pl_pos.y + 1][pl_pos.x] == 'C')
	{
		game->parsing.coin--;
		game->parsing.map[pl_pos.y + 1][pl_pos.x] = 'P';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
	else if (game->parsing.map[pl_pos.y + 1][pl_pos.x] == 'E'
		&& !game->parsing.coin)
		guard_free_map(&game->parsing.map);
	else if (game->parsing.map[pl_pos.y + 1][pl_pos.x]
			== 'E' && game->parsing.coin != 0)
	{
		game->parsing.map[pl_pos.y + 1][pl_pos.x] = 'Q';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
}

void	move_right(t_game *game)
{
	t_position	pl_pos;

	pl_pos = game->parsing.pos;
	if (game->parsing.map[pl_pos.y][pl_pos.x + 1] == '0')
	{
		swap(&game->parsing.map[pl_pos.y][pl_pos.x],
			&game->parsing.map[pl_pos.y][pl_pos.x + 1]);
	}
	else if (game->parsing.map[pl_pos.y][pl_pos.x + 1] == 'C')
	{
		game->parsing.coin--;
		game->parsing.map[pl_pos.y][pl_pos.x + 1] = 'P';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
	else if (game->parsing.map[pl_pos.y][pl_pos.x + 1] == 'E'
		&& !game->parsing.coin)
		guard_free_map(&game->parsing.map);
	else if (game->parsing.map[pl_pos.y][pl_pos.x + 1]
			== 'E' && game->parsing.coin != 0)
	{
		game->parsing.map[pl_pos.y][pl_pos.x + 1] = 'Q';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
}

void	move_up(t_game *game)
{
	t_position	pl_pos;

	pl_pos = game->parsing.pos;
	if (game->parsing.map[pl_pos.y - 1][pl_pos.x] == '0')
	{
		swap(&game->parsing.map[pl_pos.y][pl_pos.x],
			&game->parsing.map[pl_pos.y - 1][pl_pos.x]);
	}
	else if (game->parsing.map[pl_pos.y - 1][pl_pos.x] == 'C')
	{
		game->parsing.coin--;
		game->parsing.map[pl_pos.y - 1][pl_pos.x] = 'P';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
	else if (game->parsing.map[pl_pos.y - 1][pl_pos.x] == 'E'
		&& !game->parsing.coin)
		guard_free_map(&game->parsing.map);
	else if (game->parsing.map[pl_pos.y][pl_pos.x + 1]
			== 'E' && game->parsing.coin != 0)
	{
		game->parsing.map[pl_pos.y - 1][pl_pos.x] = 'Q';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
}
