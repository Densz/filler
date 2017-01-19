/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:18:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/19 18:21:40 by dzheng           ###   ########.fr       */
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
	t_coor		coor;
	int			i;
	char		*tab;
	char		*pc;

	tab = ft_strnew(0);
	tab[0] = '\0';
	pc = ft_strnew(0);
	pc[0] = '\0';
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '$' && line[1] == '$')
			coor.player = ((ft_atoi(&line[9]) == 1) ? 'O' : 'X');
		else if (line[0] == 'P' && line[1] == 'l')
			coor = ft_get_tab_coor(coor, line);
		else if (line[0] == 'P' && line[1] == 'i')
			coor = ft_get_pc_coor(coor, line);
		else if (ft_isdigit(line[0]) == 1)
			tab = ft_get_tab(line, tab);
		else if (line[0] == '.' || line[0] == '*')
		{
			pc = ft_get_pc(line, pc);
			i++;
		}
		if (coor.pc_i == i && coor.pc_i != 0)
		{
			coor.pc = ft_strsplit(pc, '\n');
			coor.tab = ft_strsplit(tab, '\n');
			ft_print_grid(coor.pc);
			ft_print_grid(coor.tab);
			sleep(10);
			break ;
		}
	}
	return (0);
}

/*
		//PRINT LINE
		ft_putstr_fd("\033[36m", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\033[0m", 2);

		//VERIF PLAYER
		ft_putstr_fd("\033[31m", 2);
		ft_putstr_fd("Player test :", 2);
		ft_putchar_fd(coor.player, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\033[0m", 2);

		// VERIF TAILLE TAB
		ft_putstr_fd("\033[31m", 2);
		ft_putstr_fd("coord tab :", 2);
		ft_putnbr_fd(coor.tab_i, 2);
		ft_putstr_fd("\n", 2);
		ft_putnbr_fd(coor.tab_j, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\033[0m", 2);
		
		// VERIF TAILLE PCS
		ft_putstr_fd("\033[31m", 2);
		ft_putstr_fd("coord pieces :", 2);
		ft_putnbr_fd(coor.pc_i, 2);
		ft_putstr_fd("\n", 2);
		ft_putnbr_fd(coor.pc_j, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\033[0m", 2);

		//PRINT TAB
		ft_putstr_fd("\033[31m", 2);
		ft_putstr_fd(coor.tab, 2);
		ft_putstr_fd("\033[0m", 2);

		//PRINT PC
		ft_putstr_fd("\033[31m", 2);
		ft_putstr_fd(coor.pc, 2);
		ft_putstr_fd("\033[0m", 2);		
*/
