/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:36:30 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/21 21:02:11 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_solve(t_coor coor)
{
	static int		count_turns = 0;

	count_turns++;
	if (count_turns < 15)
	{
		fprintf(stderr, "-- TOUJOURS PLUS HAUT --\n");
		coor = ft_fill_on_top(coor);
	}
	else
	{
		fprintf(stderr, "-- NIQUE LE !! --\n");
		coor = ft_surround_him(coor);
	}
	ft_printf("%d %d\n", coor.x, coor.y);
}
