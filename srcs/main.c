/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:18:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/22 12:01:27 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			free_filler(char **map, char **pc, t_coor **coor)
{
	ft_memdel((void **)map);
	ft_memdel((void **)pc);
	ft_memdel((void **)coor);
}

int				main(void)
{
	char		*line;
	t_coor		*coor;
	char		*map;
	char		*pc;

	map = ft_strnew(0);
	pc = ft_strnew(0);
	coor = (t_coor *)malloc(sizeof(t_coor));
	while (get_next_line(0, &line) > 0)
	{
		ft_check_line(coor, line, &pc, &map);
		if (coor->done == 1)
		{
			coor->pc.shape = ft_strsplit(pc, '\n');
			coor->map = ft_strsplit(map, '\n');
			free(pc);
			free(map);
			ft_get_coor_stars(coor);
			ft_solve(coor);
			map = ft_strnew(0);
			pc = ft_strnew(0);
		}
	}
	free_filler(&map, &pc, &coor);
	return (0);
}
