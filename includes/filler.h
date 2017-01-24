/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:22:07 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/20 14:16:48 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../ft_printf/includes/ft_printf.h"
# include <stdio.h>

typedef struct			s_pc
{
	char				**shape;
	int					x;
	int					y;
}						t_pc;

typedef struct 			s_coor
{
	char				player;
	int					tab_i;
	int					tab_j;
	int					pc_i;
	int					pc_j;
	char				**tab;
	t_pc				pc;
}						t_coor;

//GET DATA
t_coor					ft_check_line(t_coor coor, char *line, char **tab, char **pc);
t_coor					ft_get_tab_coor(t_coor coor, char *line);
t_coor					ft_get_pc_coor(t_coor coor, char *line);
char					*ft_get_tab(char *line, char *tab);
char					*ft_get_pc(char *line, char *pc);

t_coor					ft_get_star(t_coor coor);
void					ft_algo(t_coor coor);
int						ft_count_star(t_coor coor);

#endif