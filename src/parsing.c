/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:59:57 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/24 19:02:18 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_top_bottom(t_parsing *sl)
{
	sl->i = -1;
	while (++sl->i < sl->s_len)
	{
		if (sl->map[0][sl->i] != '1'
			|| sl->map[sl->s_count - 1][sl->i] != '1')
			error(sl, 2);
	}
}

void	check_right_left(t_parsing *sl)
{
	sl->i = 1;
	while (sl->map[sl->i])
	{
		if (sl->map[sl->i][0] != '1'
			|| sl->map[sl->i][sl->s_len - 1] != '1')
			error(sl, 3);
		sl->i++;
	}
}

void	check_components(t_parsing *sl)
{
	sl->i = 1;
	sl->coin = 0;
	sl->exit = 0;
	sl->player = 0;
	while (sl->map[sl->i])
	{
		sl->j = 0;
		while (sl->map[sl->i][sl->j])
		{
			if (sl->map[sl->i][sl->j] == 'C')
				sl->coin++;
			if (sl->map[sl->i][sl->j] == 'P')
				sl->player++;
			if (sl->map[sl->i][sl->j] == 'P')
				sl->pos = (t_position){(int)sl->j, (int)sl->i};
			if (sl->map[sl->i][sl->j] == 'E')
				sl->exit++;
			sl->j++;
		}
	sl->i++;
	}
	if (sl->player != 1)
		error(sl, 4);
	if (sl->coin < 1 || sl->exit < 1)
		error(sl, 5);
}

void	check_wall(t_parsing *sl)
{
	sl->i = 0;
	sl->j = 0;
	while (sl->map[sl->i])
	{
		sl->j = 0;
		while (sl->map[sl->i][sl->j])
		{
			if (sl->map[sl->i][sl->j] == '1' ||
			sl->map[sl->i][sl->j] == '0' ||
			sl->map[sl->i][sl->j] == 'C' ||
			sl->map[sl->i][sl->j] == 'P' ||
			sl->map[sl->i][sl->j] == 'E' ||
			sl->map[sl->i][sl->j] == '\n')
				sl->j++;
			else
				error(sl, 1);
		}
		sl->i++;
	}
	check_top_bottom(sl);
	check_right_left(sl);
	check_components(sl);
}

void	validation(t_parsing *sl, int fd, char *str)
{
	sl->s_count = string_count(str);
	if (sl->s_count > 2)
	{
		sl->map = map_matrix(sl->s_count, fd);
		sl->s_len = ft_strlen(sl->map[0]) - 1;
		check_slen(sl);
		check_wall(sl);
	}
}
