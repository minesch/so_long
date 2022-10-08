/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:38:21 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/25 18:12:02 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	move_right(t_game *game)
{
	t_position	pl_pos;

	pl_pos = game->parsing.pos;
	if (game->parsing.map[pl_pos.y][pl_pos.x + 1]
			== 'E' && game->coin != 0)
	{
		game->parsing.map[pl_pos.y][pl_pos.x + 1] = 'Q';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
		game->parsing.pos.x++;
	}
	else if (game->parsing.map[pl_pos.y][pl_pos.x + 1]
		== 'E' && game->coin == 0)
		guard_free_map(&game->parsing.map);
	else if (game->parsing.map[pl_pos.y][pl_pos.x + 1] != '1')
	{
		if (game->parsing.map[pl_pos.y][pl_pos.x + 1] == 'C')
			game->coin--;
		game->parsing.map[pl_pos.y][pl_pos.x + 1] = 'P';
		game->parsing.pos.x++;
		if (game->parsing.map[pl_pos.y][pl_pos.x] == 'Q')
			game->parsing.map[pl_pos.y][pl_pos.x] = 'E';
		else
			game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
}

void	move_up(t_game *game)
{
	t_position	pl_pos;

	pl_pos = game->parsing.pos;
	if (game->parsing.map[pl_pos.y - 1][pl_pos.x]
			== 'E' && game->coin != 0)
	{
		game->parsing.map[pl_pos.y - 1][pl_pos.x] = 'Q';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
		game->parsing.pos.y--;
	}
	else if (game->parsing.map[pl_pos.y - 1][pl_pos.x]
		== 'E' && game->coin == 0)
		guard_free_map(&game->parsing.map);
	else if (game->parsing.map[pl_pos.y - 1][pl_pos.x] != '1')
	{
		if (game->parsing.map[pl_pos.y - 1][pl_pos.x] == 'C')
			game->coin--;
		game->parsing.map[pl_pos.y - 1][pl_pos.x] = 'P';
		game->parsing.pos.y--;
		if (game->parsing.map[pl_pos.y][pl_pos.x] == 'Q')
			game->parsing.map[pl_pos.y][pl_pos.x] = 'E';
		else
			game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
}

void	move_left(t_game *game)
{
	t_position	pl_pos;

	pl_pos = game->parsing.pos;
	if (game->parsing.map[pl_pos.y][pl_pos.x - 1]
			== 'E' && game->coin != 0)
	{
		game->parsing.map[pl_pos.y][pl_pos.x - 1] = 'Q';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
		game->parsing.pos.x--;
	}
	else if (game->parsing.map[pl_pos.y][pl_pos.x - 1]
		== 'E' && game->coin == 0)
		guard_free_map(&game->parsing.map);
	else if (game->parsing.map[pl_pos.y][pl_pos.x - 1] != '1')
	{
		if (game->parsing.map[pl_pos.y][pl_pos.x - 1] == 'C')
			game->coin--;
		game->parsing.map[pl_pos.y][pl_pos.x - 1] = 'P';
		game->parsing.pos.x--;
		if (game->parsing.map[pl_pos.y][pl_pos.x] == 'Q')
			game->parsing.map[pl_pos.y][pl_pos.x] = 'E';
		else
			game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
}

void	move_down(t_game *game)
{
	t_position	pl_pos;

	pl_pos = game->parsing.pos;
	if (game->parsing.map[pl_pos.y + 1][pl_pos.x]
			== 'E' && game->coin != 0)
	{
		game->parsing.map[pl_pos.y + 1][pl_pos.x] = 'Q';
		game->parsing.map[pl_pos.y][pl_pos.x] = '0';
		game->parsing.pos.y++;
	}
	else if (game->parsing.map[pl_pos.y + 1][pl_pos.x]
		== 'E' && game->coin == 0)
		guard_free_map(&game->parsing.map);
	else if (game->parsing.map[pl_pos.y + 1][pl_pos.x] != '1')
	{
		if (game->parsing.map[pl_pos.y + 1][pl_pos.x] == 'C')
			game->coin--;
		game->parsing.map[pl_pos.y + 1][pl_pos.x] = 'P';
		game->parsing.pos.y++;
		if (game->parsing.map[pl_pos.y][pl_pos.x] == 'Q')
			game->parsing.map[pl_pos.y][pl_pos.x] = 'E';
		else
			game->parsing.map[pl_pos.y][pl_pos.x] = '0';
	}
}
