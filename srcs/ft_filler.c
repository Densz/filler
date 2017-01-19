/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:18:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/19 15:56:11 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
/*
t_coor			ft_get_map(t_coor coor, char **line)
{
	int			i;
	char		*tmp;

	i = 0;
	if (*line[0] == ' ' && *line[1] == ' ' && *line[2] == ' ' && *line[3] == ' ')
	{
		coor.tab = ft_strnew(0);
		coor.tab[0] = '\0';
		get_next_line(0, line);
		while (i < coor.tab_i)
		{
			tmp = coor.tab;
			coor.tab = ft_strjoin(ft_strjoin(tmp, line[4]), "\n");
			free(tmp);
			get_next_line(0, line);
			i++;
		}
	}
	sleep(2);
	return (coor);
}
*/
t_coor			ft_get_data(t_coor coor, char *line)
{
	if ((ft_strchr(line, 'p')))
	{
		line = ft_strchr(line, 'p');
		coor.player = ((ft_atoi(&line[1]) == 1) ? 'O' : 'X');
	}
	else if ((ft_strchr(line, 'P')))
	{
		if ((ft_strchr(line, 'l')))
		{
			line = ft_strchr(line, 'l');
			coor.tab_i = ft_atoi(&line[6]);
			coor.tab_j = ft_atoi(&line[9]);
		}
		else if ((ft_strchr(line, 'i')))
		{
			line = ft_strchr(line, 'i');
			coor.pc_i = ft_atoi(&line[4]);
			coor.pc_j = ft_atoi(&line[6]);
		}
	}
	return (coor);
}

int				main(void)
{
	char		*line;
	t_coor		coor;

	while (get_next_line(0, &line) != -1)
	{
		ft_putstr_fd("\033[36m", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\033[0m", 2);
		coor = ft_get_data(coor, line);
		sleep(2);
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
