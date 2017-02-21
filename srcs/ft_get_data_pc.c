/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_pc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Champi <Champi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:45:16 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/21 23:47:42 by Champi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_count_stars(t_coor *coor)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (coor->pc.shape[i])
	{
		j = 0;
		while (coor->pc.shape[i][j])
		{
			if (coor->pc.shape[i][j] == '*')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void		ft_get_coor_stars(t_coor *coor)
{
	int		i;
	int		j;
	int		coor_n;

	i = 0;
	coor_n = 0;
	coor->pc.cnt_stars = ft_count_stars(coor);
	coor->pc.stars_i = (int *)malloc(sizeof(int) * coor->pc.cnt_stars);
	coor->pc.stars_j = (int *)malloc(sizeof(int) * coor->pc.cnt_stars);
	while (coor->pc.shape[i] && coor_n < coor->pc.cnt_stars)
	{
		j = 0;
		while (coor->pc.shape[i][j] && coor_n < coor->pc.cnt_stars)
		{
			if (coor->pc.shape[i][j] == '*')
			{
				coor->pc.stars_i[coor_n] = i;
				coor->pc.stars_j[coor_n] = j;
				coor_n++;
			}
			j++;
		}
		i++;
	}
}
