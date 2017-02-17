/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:45:16 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/17 17:05:03 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coor		ft_update_position_back(t_coor coor, int y_decal, int x_decal)
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

t_coor		ft_update_position(t_coor coor, int y_decal, int x_decal)
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

int			ft_count_stars(t_coor coor)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (coor.pc.shape[i])
	{
		j = 0;
		while (coor.pc.shape[i][j])
		{
			if (coor.pc.shape[i][j] == '*')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_coor		ft_get_coor_stars(t_coor coor)
{
	int		i;
	int		j;
	int		coor_n;

	i = 0;
	coor_n = 0;
	coor.pc.stars_i = (int *)malloc(sizeof(int) * ft_count_stars(coor));
	coor.pc.stars_j = (int *)malloc(sizeof(int) * ft_count_stars(coor));
	while (coor.pc.shape[i] && coor_n < ft_count_stars(coor))
	{
		j = 0;
		while (coor.pc.shape[i][j] && coor_n < ft_count_stars(coor))
		{
			if (coor.pc.shape[i][j] == '*')
			{
				coor.pc.stars_i[coor_n] = i;
				coor.pc.stars_j[coor_n] = j;
				coor_n++;
			}
			j++;
		}
		i++;
	}
	return (coor);
}
