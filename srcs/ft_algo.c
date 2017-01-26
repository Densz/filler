/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:47:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/26 14:14:28 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coor		ft_update_position(t_coor coor, int i, int j) //CA MARCHE
{
	int		x_decal;
	int		y_decal;
	int		index;

	index = 0;
	x_decal = j - coor.pc.stars_j[0];
	y_decal = i - coor.pc.stars_i[0];
	while (index < ft_count_stars(coor))
	{
		coor.pc.stars_i[index] = coor.pc.stars_i[index] + y_decal;
		coor.pc.stars_j[index] = coor.pc.stars_j[index] + x_decal;
		index++;
	}
	return (coor);
}

int			ft_checker(t_coor coor, int i, int j)
{
	int		index;

	index = 1;
	i = 0;
	coor = ft_update_position(coor, i, j);
	while (coor.map[i])
	{
		j = 0;
		while (coor.map[i][j])
		{
			if (i == coor.pc.stars_i[index] && j == coor.pc.stars_j[index])
			{
				if(coor.map[i][j] == '.')
					index++;
			}
			j++;
		}
		i++;
	}
	if (index == ft_count_stars(coor))
		return (1);
	return (0);
}

void		ft_algo(t_coor coor)
{
	int		i;
	int		j;
	int		tmp_i;
	int		tmp_j;

	i = 0;
	tmp_i = coor.pc.stars_i[0];
	tmp_j = coor.pc.stars_j[0];
	while (coor.map[i])
	{
		j = 0;
		while (coor.map[i][j])
		{
			if (coor.map[i][j] == coor.id)
				if (ft_checker(coor, i, j) == 1)
				{
					ft_printf("%d %d\n", i - tmp_i, j - tmp_j);
					free(coor.pc.stars_i);
					free(coor.pc.stars_j);
				}
			j++;
		}
		i++;
	}
	ft_printf("0 0\n", i - tmp_i, j - tmp_j);
}