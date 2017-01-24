/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:18:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/20 13:47:21 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			ft_print_grid(char **grid)
{
	int			i;

	i = 0;
	while (grid[i])
	{
		fprintf(stderr, "\033[33m%s\033[0m\n", grid[i]);
		i++;
	}
}

int				main(void)
{
	char		*line;
	int			i;
	t_coor		coor;
	char		*tab;
	char		*pc;

	i = 0;
	tab = ft_strdup("");
	pc = ft_strdup("");
	while (get_next_line(0, &line) != -1)
	{
		i++;
		coor = ft_check_line(coor, line, &tab, &pc);
		if (i == 4 + coor.pc_i + coor.tab_i)
		{
			coor.pc.shape = ft_strsplit(pc, '\n');
			coor.tab = ft_strsplit(tab, '\n');
			ft_memdel((void **)&tab);
			ft_memdel((void **)&pc);
			coor = ft_get_star(coor);
			ft_algo(coor);
			i = 0;
			break ;
		}
	}
	return (0);
}
