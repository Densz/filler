/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_coor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:59:26 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/21 20:48:01 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coor		ft_check_line(t_coor coor, char *line, char **pc, char **map)
{
	static int		compt = 0;

	if (line[0] == '$' && line[1] == '$')
		coor.id = ((ft_atoi(&line[10]) == 1) ? 'O' : 'X');
	else if (line[0] == 'P' && line[1] == 'l')
		coor = ft_get_map_coor(coor, line);
	else if (line[0] == 'P' && line[1] == 'i')
		coor = ft_get_pc_coor(coor, line);
	else if (ft_isdigit(line[0]) == 1)
		*map = ft_get_map(line, *map);
	else if (line[0] == '.' || line[0] == '*')
	{
		compt++;
		*pc = ft_get_pc(line, *pc);
		if (compt == coor.pc.pc_i)
		{
			coor.done = 1;
			compt = 0;
		}
	}
	return (coor);
}

t_coor		ft_get_map_coor(t_coor coor, char *line)
{
	coor.map_i = ft_atoi(&line[7]);
	line = ft_strchr(&line[8], ' ');
	coor.map_j = ft_atoi(&line[0]);
	return (coor);
}

t_coor		ft_get_pc_coor(t_coor coor, char *line)
{
	coor.pc.pc_i = ft_atoi(&line[5]);
	line = ft_strchr(&line[6], ' ');
	coor.pc.pc_j = ft_atoi(&line[0]);
	return (coor);
}

char		*ft_get_map(char *line, char *map)
{
	char	*tmp;

	tmp = map;
	map = ft_strjoin(ft_strjoin(tmp, &line[4]), "\n");
	ft_memdel((void **)&tmp);
	return (map);
}

char		*ft_get_pc(char *line, char *pc)
{
	char	*tmp;

	tmp = pc;
	pc = ft_strjoin(ft_strjoin(tmp, line), "\n");
	ft_memdel((void **)&tmp);
	return (pc);
}