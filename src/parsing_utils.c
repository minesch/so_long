/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 01:00:01 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/28 20:46:35 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_parsing *sl, int indicate)
{
	if (indicate == 1)
		write(2, "...ERROR...\n...WRONG_COMPONENT...\n", 34);
	if (indicate == 2)
		write(2, "...ERROR...\n...WALL_top/bottom...\n", 34);
	if (indicate == 3)
		write(2, "...ERROR...\n...WALL_left/right...\n", 34);
	if (indicate == 4)
		write(2, "...ERROR...\n...PLAYER_DOES_NOT_EXISTS...\n", 41);
	if (indicate == 5)
		write(2, "...ERROR...\n...COMPONENT_DEFICIENCY...\n", 39);
	if (indicate == 6)
		write(2, "...ERROR...\n...INVALID_MAP...\n", 30);
	if (indicate == 7)
		write(2, "...ERROR...\n...FILE_DOES_NOT_EXISTS...\n", 39);
	sl->i = 0;
	if (indicate != 7)
		guard_free_map(&sl->map);
	exit(1);
}

int	guard_free_map(char ***map)
{
	int	i;

	if (!map || !*map)
		exit (0);
	i = -1;
	while ((*map)[++i])
		free((*map)[i]);
	free(*map);
	*map = 0;
	exit (0);
	return (0);
}

void	check_slen(t_parsing *sl)
{
	size_t	len;

	len = 0;
	sl->i = 0;
	while (sl->map[sl->i])
	{
		len = ft_strlen(sl->map[sl->i]) - 1;
		if (len != sl->s_len)
			error(sl, 1);
		sl->i++;
	}
}

int	get_coin(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				++count;
			++j;
		}
		++i;
	}
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
