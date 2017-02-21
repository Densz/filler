/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_when_you_can.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:47:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/21 16:41:33 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_not_surrounded(int i, int j, t_coor coor)
{
	if (i + 1 < coor.map_i)
		if (coor.map[i + 1][j] == '.')
			return (1);
	if (i - 1 >= 0)
		if (coor.map[i - 1][j] == '.')
			return (1);
	if (j + 1 >= 0)
		if (coor.map[i][j + 1] == '.')
			return (1);
	if (j - 1 >= 0)
		if (coor.map[i][j - 1] == '.')
			return (1);
	return (0);
}

t_coor		ft_fill_when_you_can(t_coor coor)
{
	int		i;
	int		j;
	int		count;
	int		gap;

	i = -1;
	gap = 300;
	while (coor.map[++i])
	{
		j = -1;
		while (coor.map[i][++j])
		{
			if (coor.map[i][j] == coor.id && ft_not_surrounded(i, j, coor))
			{
				coor.gap = 300;
				count = 0;
				while (count < ft_count_stars(coor))
				{	
					if (ft_checker(&coor, i, j, count) == 1 && coor.gap < gap)
					{
						coor.x = i - coor.pc.stars_i[count];
						coor.y = j - coor.pc.stars_j[count];
						gap = coor.gap;
					}
					count++;
				}
			}
		}
	}
	return (coor);
}