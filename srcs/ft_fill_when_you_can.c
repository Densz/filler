/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_when_you_can.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:47:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/27 16:18:10 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_fill_when_you_can(t_coor coor) //PARSING AC *MAP
{
	int		i;
	int		j;
	int		count;

	i = 0;
	fprintf(stderr, "###   OU TU PEUX   #####\n");
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