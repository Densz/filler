/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:18:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/26 14:26:05 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** FONCTION A ENLEVER
*/
void			ft_print_coor_of_stars(t_coor coor)
{
	int			i;

	i = 0;
	fprintf(stderr, "Stars :\n");
	while (i < ft_count_stars(coor))
	{
		fprintf(stderr, "%d. X = %i - Y = %i\n", i + 1, coor.pc.stars_j[i], coor.pc.stars_i[i]);
		i++;
	}
}


void			ft_print_grid(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		fprintf(stderr, "\033[33m%s\n\033[0m", str[i]);
		i++;
	}
}

int				main(void)
{
	char		*line;
	t_coor		coor;
	char		*map;
	char		*pc;

	map = ft_strnew(0);
	pc = ft_strnew(0);
	while (get_next_line(0, &line) != -1)
	{
		coor = ft_check_line(coor, line, &pc, &map);
		if (coor.done == 1)
		{
				coor.pc.shape = ft_strsplit(pc, '\n');
				coor.map = ft_strsplit(map, '\n');
				coor = ft_get_coor_stars(coor);
				ft_algo(coor); //JEN SUIS ICI
				map = ft_strnew(0);
				pc = ft_strnew(0);
				coor.done = 0;
		}
	}
	sleep (1);
	return (0);
}
