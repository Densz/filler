/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_when_you_can.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:47:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/18 14:06:06 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coor		ft_fill_when_you_can(t_coor coor)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	coor.gap = 90000;
	fprintf(stderr, "###   ALLEEEZZ  NIQUE LE !!   #####\n");
	while (coor.map[++i])
	{
		j = 0;
		while (coor.map[i][j])
		{
			if (coor.map[i][j] == coor.id)
			{
				count = 0;
				while (count++ < ft_count_stars(coor))
				{	
					if (ft_checker(&coor, i, j, count) == 1)
					{
						coor.x = i - coor.pc.stars_i[count];
						coor.y = j - coor.pc.stars_j[count];
					}
				}				
			}
			j++;
		}
	}
	return (coor);
}