/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:47:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/26 16:43:15 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coor		ft_update_position_back(t_coor coor, int y_decal, int x_decal) //CA MARCHE
{
	int		index;

	index = 0;
	while (index < ft_count_stars(coor))
	{
		coor.pc.stars_i[index] -= y_decal;
		coor.pc.stars_j[index] -= x_decal;
		index++;
	}
	return (coor);
}

t_coor		ft_update_position(t_coor coor, int y_decal, int x_decal) //CA MARCHE
{
	int		index;

	index = 0;
	while (index < ft_count_stars(coor))
	{
		coor.pc.stars_i[index] += y_decal;
		coor.pc.stars_j[index] += x_decal;
		index++;
	}
	return (coor);
}

int			ft_checker(t_coor coor, int i, int j, int count)
{
	int		index;
	int		x_decal;
	int		y_decal;
	int		error;

	index = 0;
	error = 0;
	x_decal = j - coor.pc.stars_j[count];
	y_decal = i - coor.pc.stars_i[count];
	coor = ft_update_position(coor, y_decal, x_decal);
	i = 0;
	while (coor.map[i])
	{
		j = 0;
		while (coor.map[i][j] && index < ft_count_stars(coor))
		{
			if (i == coor.pc.stars_i[index] && j == coor.pc.stars_j[index] && coor.map[i][j] == coor.id)
			{
				index++;
				error++;
			}
			if (i == coor.pc.stars_i[index] && j == coor.pc.stars_j[index] && coor.map[i][j] == '.')
				index++;
			j++;
		}
		i++;
	}
	coor = ft_update_position_back(coor, y_decal, x_decal);
	if (index == ft_count_stars(coor) && error == 1)
		return (1);
	return (0);
}

void		ft_algo(t_coor coor)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	while (coor.map[i])
	{
		j = 0;
		while (coor.map[i][j])
		{
			if (coor.map[i][j] == coor.id)
			{
				count = 0;
				while (count < ft_count_stars(coor))
				{	
					if (ft_checker(coor, i, j, count) == 1)
					{
						ft_printf("%d %d\n", (i - coor.pc.stars_i[count]), (j - coor.pc.stars_j[count]));
						return ;
					}
					count++;
				}				
			}
			j++;
		}
		i++;
	}
	ft_printf("0 0\n");
}