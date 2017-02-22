/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:36:30 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/22 19:21:19 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	check_position(t_coor *coor)
{
	int				i;
	int				j;
	int				me;
	int				him;

	i = -1;
	me = 0;
	him = 0;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] != coor->id && coor->map[i][j] != '.')
				him = i;
			if (coor->map[i][j] == coor->id)
				me = i;
		}
	}
	coor->strat.is_below = (me > him ? 1 : 0);
}

int		filled_on_top(t_coor *coor)
{
	int				i;
	int				j;

	i = -1;
	while (coor->map[++i])
	{
		j = -1;
		while (coor->map[i][++j])
		{
			if (coor->map[i][j] == coor->id)
			{
				if (i == 0)
					return (1);
				else
					return (0);
			}
		}
	}
	return (0);
}

void	ft_solve(t_coor *coor)
{
	static int		count_turns = 0;
	int				i;
	int				j;
	int				count;

	i = -1;
	j = -1;
	count = -1;
	count_turns++;
	if (count_turns == 1)
		check_position(coor);
	if (!filled_on_top(coor) && coor->strat.is_below)
		ft_fill_on_top(coor);
	else
		ft_surround_him(coor, i, j, count);
	ft_printf("%d %d\n", coor->x, coor->y);
	coor->x = 0;
	coor->y = 0;
	coor->done = 0;
}
