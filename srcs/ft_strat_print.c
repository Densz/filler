/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:36:30 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/21 20:45:04 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_solve(t_coor coor)
{
	static int		count_turns = 0;

	count_turns++;
	fprintf(stderr, "count_turns = %d\n", count_turns);
	coor = ft_surround_him(coor);
	ft_printf("%d %d\n", coor.x, coor.y);
}
