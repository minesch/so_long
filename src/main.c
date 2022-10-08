/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azakarya <azakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:29:20 by azakarya          #+#    #+#             */
/*   Updated: 2022/09/24 19:12:47 by azakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int ac, char **av)
{
	t_game		game;
	int			fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error(&game.parsing, 7);
	if (ac == 2 && (valid_name(av[1]) == 0))
	{
		validation(&game.parsing, fd, av[1]);
		game.coin = get_coin(game.parsing.map);
		start_game(&game);
	}
	else
		error(&game.parsing, 6);
	close(fd);
	return (0);
}
