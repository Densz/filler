/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:11:46 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/17 17:41:12 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_checker_map(t_coor coor)
{
	int		index;
	int		error;
	int		i;
	int		j;

	index = 0;
	error = 0;
	i = -1;
	while (coor.map[++i])
	{
		j = 0;
		while (coor.map[i][j] && index < ft_count_stars(coor))
		{
			if (i == coor.pc.stars_i[index] && j == coor.pc.stars_j[index]\
			&& coor.map[i][j] == coor.id)
			{
				index++;
				error++;
			}
			else if (i == coor.pc.stars_i[index] && j == coor.pc.stars_j[index]\
			&& coor.map[i][j] == '.')
				index++;
			j++;
		}
	}
	if (index == ft_count_stars(coor) && error == 1)
		return (1);
	return (0);
}

int			ft_checker(t_coor coor, int i, int j, int count)
{
	int		x_decal;
	int		y_decal;
	int		ret;

	ret = 0;
	x_decal = j - coor.pc.stars_j[count];
	y_decal = i - coor.pc.stars_i[count];
	coor = ft_update_position(coor, y_decal, x_decal);
	ret = ft_checker_map(coor);
	coor = ft_update_position_back(coor, y_decal, x_decal);
	if (ret == 1)
		return (1);
	return (0);
}
