/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Champi <Champi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:36:30 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/21 23:52:44 by Champi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_solve(t_coor *coor)
{
	static int		count_turns = 0;

	count_turns++;
	if (count_turns < 40)
	{
		fprintf(stderr, "-- TOUJOURS PLUS HAUT --\n");
		ft_fill_on_top(coor);
	}
	else
	{
		fprintf(stderr, "-- NIQUE LE !! --\n");
		ft_surround_him(coor);
	}
	ft_printf("%d %d\n", coor->x, coor->y);
}

//15 is good when x -> below O and map01
