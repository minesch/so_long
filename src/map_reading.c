/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:55:01 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/19 01:54:41 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	valid_name(char *str)
{
	char	*format;
	int		i;

	if (!(str && (int)ft_strlen(str) > 4))
		return (-1);
	format = ".ber";
	i = 0;
	while (str[i + 4])
		i++;
	while (str[i] && str[i] == *format++)
		i++;
	if ((int)ft_strlen(str) != i)
		return (-1);
	return (0);
}

int	string_count(char *path)

{
	int		s_count;
	int		fd;
	char	*line;

	s_count = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		s_count++;
		free(line);
	}
	close(fd);
	return (s_count);
}

char	**map_matrix(int s_count, int fd)
{
	char	**map;
	char	*tmp;
	int		i;
	int		count;

	count = s_count + 1;
	map = (char **)malloc(sizeof(char *) * count);
	i = 0;
	while (i < count - 1)
	{
		tmp = get_next_line(fd);
		map[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	map[i] = 0;
	return (map);
}
