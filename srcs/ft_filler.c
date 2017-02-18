/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:18:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/18 14:45:00 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				main(void)
{
	char		*line;
	t_coor		coor;
	char		*map;
	char		*pc;

	map = ft_strnew(0);
	pc = ft_strnew(0);
	ft_bzero(&coor, sizeof(t_coor));
	while (get_next_line(0, &line) > 0)
	{
		coor = ft_check_line(coor, line, &pc, &map);
		if (coor.done == 1)
		{
			coor.pc.shape = ft_strsplit(pc, '\n');
			coor.map = ft_strsplit(map, '\n');
			coor = ft_get_coor_stars(coor);
			ft_solve(coor);
			coor.done = 0;
			map = ft_strnew(0);
			pc = ft_strnew(0);
		}
	}
	free(map);
	free(pc);
	return (0);
}
