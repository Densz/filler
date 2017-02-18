/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_when_you_can.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:47:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/18 16:44:02 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coor		ft_fill_when_you_can(t_coor coor)
{
	int		i;
	int		j;
	int		count;
	int		gap;

	i = -1;
	gap = 300;
//	fprintf(stderr, "###  ALLEEEZZ BAISE LE  ###\n");
	while (coor.map[++i])
	{
		j = 0;
		while (coor.map[i][j])
		{
			if (coor.map[i][j] == coor.id)
			{
				coor.gap = 300;
				count = 0;
				while (count < ft_count_stars(coor))
				{	
					if (ft_checker(&coor, i, j, count) == 1)
					{
						if (coor.gap < gap)
						{
							coor.x = i - coor.pc.stars_i[count];
							coor.y = j - coor.pc.stars_j[count];
							gap = coor.gap;
						}
					}
					count++;
				}				
			}
			j++;
		}
	}
//	fprintf(stderr, "Distance %d Player = %c\n", gap, coor.id);
	return (coor);
}