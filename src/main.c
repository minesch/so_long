/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:29:20 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/03 22:00:28 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	valid_name(char *str)
{
	char	*format;
	int		i;

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

int	handle_validation(char **tmp, char **map, int fd, int len)
{
	while (1)
	{
		if (!*tmp)
			break ;
		else
		{
			*map = ft_strjoin(*map, *tmp);
			free(*tmp);
		}
		*tmp = get_next_line(fd);
		if ((int)ft_strlen(*tmp) != len)
		{
			if (*tmp)
				free(*tmp);
			return (-1);
		}
	}
	return (0);
}

int	validation(char *str, char **map)
{
	int		fd;
	int		len;
	char	*tmp;

	if (valid_name(str) == 0)
	{
		fd = open(str, O_RDONLY);
		tmp = get_next_line(fd);
		len = ft_strlen(tmp);
		if (handle_validation(&tmp, map, fd, len) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	char	*str;

	str = "";
	if (ac == 2)
	{
		validation(av[1], &str);
		printf("%s\n", str);
	}
	else
		write(2, "Mapy ches gre aper\n", 19);
	return (0);
}
