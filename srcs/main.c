/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:18:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/23 17:21:12 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			free_tab(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void			free_filler(char **map, char **pc, t_coor **coor)
{
	ft_memdel((void **)map);
	ft_memdel((void **)pc);
	ft_memdel((void **)coor);
}

void			parsing_done(t_coor *coor, char *map, char *pc)
{
	coor->pc.shape = ft_strsplit(pc, '\n');
	coor->map = ft_strsplit(map, '\n');
	ft_get_coor_stars(coor);
	ft_solve(coor);
	free(map);
	free(pc);
	free_tab(coor->pc.shape);
	free_tab(coor->map);
	free(coor->pc.stars_i);
	free(coor->pc.stars_j);
}

int				main(void)
{
	char		*line;
	t_coor		*coor;
	char		*map;
	char		*pc;

	map = ft_strnew(0);
	pc = ft_strnew(0);
	coor = ft_memalloc(sizeof(t_coor));
	while (get_next_line(0, &line) > 0)
	{
		ft_check_line(coor, line, &pc, &map);
		if (coor->done == 1)
		{
			parsing_done(coor, map, pc);
			map = ft_strnew(0);
			pc = ft_strnew(0);
		}
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	free_filler(&map, &pc, &coor);
	return (0);
}
