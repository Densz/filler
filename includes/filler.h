/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:22:07 by dzheng            #+#    #+#             */
/*   Updated: 2017/01/27 16:12:49 by dzheng           ###   ########.fr       */
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
	int					pc_i; //TAILLE DE LA PIECE
	int					pc_j;
	int					*stars_i; //COORDONNEES DE LA PREMIERE ETOILE
	int					*stars_j;
}						t_pc;

typedef struct 			s_coor
{
	char				id; //PLAYER
	int					map_i; //TAILLE DE LA MAP
	int					map_j;
	char				**map; 
	t_pc				pc;
	int					done;
}						t_coor;

//GET_DATA.C
t_coor					ft_get_map_coor(t_coor coor, char *line);
t_coor					ft_get_pc_coor(t_coor coor, char *line);
char					*ft_get_map(char *line, char *map);
char					*ft_get_pc(char *line, char *pc);
t_coor					ft_check_line(t_coor coor, char *line, char **pc, char **map);

//GET_COORDINATE.C
t_coor					ft_get_coor_stars(t_coor coor);
int						ft_count_stars(t_coor coor);
t_coor					ft_update_position_back(t_coor coor, int y_decal, int x_decal);
t_coor					ft_update_position(t_coor coor, int y_decal, int x_decal);

//FT_CHECKER.C
int						ft_checker_map(t_coor coor);
int						ft_checker(t_coor coor, int i, int j, int count);

//FILLER.C  /--> TO DELETE AT THE END
void					ft_print_grid(char **str);
void					ft_print_coor_of_stars(t_coor coor, char *str);
void					ft_print_coor_of_dots(t_coor coor);

//ALGO.C
void					ft_solve(t_coor coor);
void					ft_fill_when_you_can(t_coor coor);
void					ft_fill_on_top(t_coor coor);

#endif