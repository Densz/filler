/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_on_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:58:39 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/27 16:25:42 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_fill_on_top(t_coor coor)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	fprintf(stderr, "###  TOUJOURS PLUS HAUT  #####\n");
	while (coor.map[i])
	{
		j = 0;
		while (coor.map[i][j])
		{
			if (coor.map[i][j] == coor.id)
			{
				count = ft_count_stars(coor) - 1;
				while (count >= 0)
				{
					if (ft_checker(coor, i, j, count) == 1)
					{
						ft_printf("%d %d\n", (i - coor.pc.stars_i[count]), (j - coor.pc.stars_j[count]));
						return ;
					}
					count--;
				}			
			}
			j++;
		}
		i++;
	}
	ft_printf("0 0\n");
}