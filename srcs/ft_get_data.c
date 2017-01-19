/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:59:26 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/19 18:21:47 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coor		ft_get_tab_coor(t_coor coor, char *line)
{
	coor.tab_i = ft_atoi(&line[7]);
	line = ft_strchr(&line[8], ' ');
	coor.tab_j = ft_atoi(&line[0]);
	return (coor);
}

t_coor		ft_get_pc_coor(t_coor coor, char *line)
{
	coor.pc_i = ft_atoi(&line[5]);
	line = ft_strchr(&line[6], ' ');
	coor.pc_j = ft_atoi(&line[0]);
	return (coor);
}

char		*ft_get_tab(char *line, char *tab)
{			
	char	*tmp;

	tmp = tab;
	tab = ft_strjoin(ft_strjoin(tmp, &line[4]), "\n");
	ft_memdel((void **)&tmp);
	return (tab);
}

char		*ft_get_pc(char *line, char *pc)
{			
	char	*tmp;

	tmp = pc;
	pc = ft_strjoin(ft_strjoin(tmp, line), "\n");
	ft_memdel((void **)&tmp);
	return (pc);
}