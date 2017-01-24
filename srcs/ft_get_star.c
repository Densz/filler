/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_star.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:45:16 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/20 14:16:52 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				ft_count_star(t_coor coor)
{
	int			i;
	int			j;
	int			count;

	i = 0;
	j = 0;
	count = 0;
	while (coor.pc.shape[i])
	{
		while (coor.pc.shape[i][j])
		{
			if (coor.pc.shape[i][j] == '*')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

t_coor			ft_get_star(t_coor coor)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (coor.pc.shape[i])
	{
		while (coor.pc.shape[i][j])
		{
			if (coor.pc.shape[i][j] == '*')
			{
				coor.pc.x = j;
				coor.pc.y = i;
				fprintf(stderr, "\033[33mCoordonnees X = %d et Y = %d;\033[0m\n", coor.pc.x, coor.pc.y);
				sleep (5);
				return (coor);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (coor);
}