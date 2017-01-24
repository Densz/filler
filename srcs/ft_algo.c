/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:47:03 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/20 16:07:47 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_pc			ft_get_next_star(t_coor coor, int i)
{
	int			count;

	while (coor.pc.shape[coor.pc.y])
	{
		while (coor.pc.shape[coor.pc.y][coor.pc.x])
		{
			if (coor.pc.shape[coor.pc.y][coor.pc.x] == '*')
				if (i == count++)
					return (coor);	
			coor.pc.x++;
		}	
		coor.pc.x = 0;
		coor.pc.y++;
	}
	return (NULL);
}
int				ft_check_if_fit(t_coor coor, int i, int j, int k)
{
	if (k > ft_count_star(coor))
			return ();
	coor.pc = ft_get_next_star(coor, k);
	if (!ft_check_if_fit(coor, i, j, k + 1))
		return (0);
}

void			ft_algo(t_coor coor)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 1;
	while (coor.tab[i])
	{
		while (coor.tab[i][j])
		{
			if (coor.tab[i]][j] == coor.player)
			{
				if (ft_check_if_fit(coor, i, j, k))
				{
					printf("%d, %d", i, j);
					return ;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}