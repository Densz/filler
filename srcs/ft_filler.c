/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:47:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/22 12:05:09 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		ft_not_surrounded(int i, int j, t_coor *coor)
{
	if (i + 1 < coor->map_i)
		if (coor->map[i + 1][j] == '.')
			return (1);
	if (i - 1 >= 0)
		if (coor->map[i - 1][j] == '.')
			return (1);
	if (j + 1 >= 0)
		if (coor->map[i][j + 1] == '.')
			return (1);
	if (j - 1 >= 0)
		if (coor->map[i][j - 1] == '.')
			return (1);
	return (0);
}

void			ft_fill_on_top(t_coor *coor)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] == coor->id && ft_not_surrounded(i, j, coor))
			{
				count = coor->pc.cnt_stars;
				while (--count >= 0)
				{
					if (ft_checker(coor, i, j, count) == 1)
					{
						coor->x = i - coor->pc.stars_i[count];
						coor->y = j - coor->pc.stars_j[count];
						return ;
					}
				}
			}
		}
	}
}

void			ft_surround_him(t_coor *coor, int i, int j, int count)
{
	int		gap;

	gap = 300;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] == coor->id && ft_not_surrounded(i, j, coor))
			{
				coor->gap = 300;
				count = -1;
				while (++count < coor->pc.cnt_stars)
				{
					if (ft_checker(coor, i, j, count) == 1 && coor->gap <= gap)
					{
						coor->x = i - coor->pc.stars_i[count];
						coor->y = j - coor->pc.stars_j[count];
						gap = coor->gap;
					}
				}
			}
		}
	}
}
