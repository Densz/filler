/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_when_you_can.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:47:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/17 17:44:24 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_fill_when_you_can(t_coor coor) //PARSING AC *MAP
{
	int		i;
	int		j;
	int		count;

	i = -1;
	fprintf(stderr, "###   ALLEEEZZ  NIQUE LE !!   #####\n");
	while (coor.map[++i])
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
						coor.x = i - coor.pc.stars_i[count];
						coor.y = j - coor.pc.stars_j[count];			
					}
					count++;
				}				
			}
			j++;
		}
	}
	ft_printf("%d %d\n", coor.x, coor.y);
}