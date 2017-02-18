/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:11:46 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/18 14:06:25 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_update_position_back(t_coor coor, int y_decal, int x_decal)
{
	int		index;

	index = 0;
	while (index < ft_count_stars(coor))
	{
		coor.pc.stars_i[index] -= y_decal;
		coor.pc.stars_j[index] -= x_decal;
		index++;
	}
}

void		ft_update_position(t_coor coor, int y_decal, int x_decal)
{
	int		index;

	index = 0;
	while (index < ft_count_stars(coor))
	{
		coor.pc.stars_i[index] += y_decal;
		coor.pc.stars_j[index] += x_decal;
		index++;
	}
}

int			ft_checker_map(t_coor *coor)
{
	int		index;
	int		error;
	int		i;
	int		j;

	index = 0;
	error = 0;
	i = -1;
	while (coor->map[++i])
	{
		j = 0;
		while (coor->map[i][j] && index < ft_count_stars(*coor))
		{
			if (i == coor->pc.stars_i[index] && j == coor->pc.stars_j[index]\
			&& coor->map[i][j] == coor->id)
			{
				index++;
				error++;
			}
			else if (i == coor->pc.stars_i[index] &&\
			j == coor->pc.stars_j[index] && coor->map[i][j] == '.')
				index++;
			j++;
		}
	}
	if (index == ft_count_stars(*coor) && error == 1)
		return (1);
	return (0);
}

int				ft_get_distance(t_coor coor, int gap, int stars)
{
	int				index;
	int				i;
	int				j;
	int				gap_tmp;

	i = -1;
	gap_tmp = 0;
	while (coor.map[++i])
	{
		j = 0;
		while (coor.map[i][j])
		{
			if (coor.map[i][j] != coor.id && coor.map[i][j] != '.')
			{
				index = 0;
				while (index < stars)
				{
					gap_tmp = ft_abs(coor.pc.stars_i[index] - i) +\
					ft_abs(coor.pc.stars_j[index] - j);
					if (gap_tmp < gap)
					{
						gap = gap_tmp;
						fprintf(stderr, "Distance %d\n", gap);
					}
					index++;
				}
			}
			j++;
		}
	}
	return (gap);
}

int			ft_checker(t_coor *coor, int i, int j, int count)
{
	int		x_decal;
	int		y_decal;
	int		ret;

	ret = 0;
	x_decal = j - coor->pc.stars_j[count];
	y_decal = i - coor->pc.stars_i[count];
	ft_update_position(*coor, y_decal, x_decal);
	ret = ft_checker_map(coor);
	coor->gap = ft_get_distance(*coor, coor->gap, ft_count_stars(*coor));
	ft_update_position_back(*coor, y_decal, x_decal);
	if (ret == 1)
		return (1);
	return (0);
}
