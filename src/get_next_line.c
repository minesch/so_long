/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:10:47 by azakarya          #+#    #+#             */
/*   Updated: 2022/08/25 21:14:02 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saver;
	char		buf[BUFFER_SIZE + 1];
	char		*print;
	int			count;
	char		*for_free;

	while (1)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
			return (0);
		buf[count] = '\0';
		if (!saver)
			saver = ft_strdup(buf);
		else
			saver = ft_strjoin(saver, buf);
		if (ft_strchr(buf, '\n') || count == 0)
			break ;
	}
	count = ft_strlen(saver) - ft_strlen(ft_strchr(saver, '\n')) + 1;
	print = ft_substr(saver, 0, count);
	for_free = saver;
	saver = ft_substr(saver, count, ft_strlen(saver));
	free(for_free);
	return (print);
}
