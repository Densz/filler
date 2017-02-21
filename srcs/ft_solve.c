/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:36:30 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/21 12:11:25 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_solve(t_coor coor)
{
	coor = ft_fill_when_you_can(coor);
	if (coor.x != 0 && coor.y != 0)
		ft_printf("%d %d\n", coor.x, coor.y);
	else
		ft_printf("0 0\n");
}
