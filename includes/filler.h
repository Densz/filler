/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:22:07 by dzheng            #+#    #+#             */
/*   Updated: 2017/02/23 15:48:58 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct			s_pc
{
	char				**shape; //Piece dans une str
	int					pc_i; //TAILLE DE LA PIECE -Y
	int					pc_j; //TAILLE DE LA PIECE -X
	int					*stars_i; //COORDONNEES DE TOUTE LES ETOILES
	int					*stars_j; //COORDONNEES DE TOUTE LES ETOILES
	int					cnt_stars;
}						t_pc;

typedef struct 			s_strat
{
	int					is_below;
	int					can_up;
}						t_strat;

typedef struct 			s_coor
{
	char				id; //PLAYER
	int					map_i; //TAILLE DE LA MAP -Y
	int					map_j; //TAILLE DE LA MAP -X
	char				**map; //MAP dans une str
	int					gap; //DISTANCE ENTRE L'ADVERSAIRE
	int					x; //coordonnees a print
	int					y; //coordonnees a print
	int					done; //Done with le parsing
	t_pc				pc;
	t_strat				strat;
}						t_coor;

//GET_DATA.C
void					ft_get_map_coor(t_coor *coor, char *line);
void					ft_get_pc_coor(t_coor *coor, char *line);
char					*ft_get_map(char *line, char *map);
char					*ft_get_pc(char *line, char *pc);
void					ft_check_line(t_coor *coor, char *line, char **pc,\
						char **map);

//GET_COORDINATE.C
void					ft_get_coor_stars(t_coor *coor);
int						ft_count_stars(t_coor *coor);
void					ft_update_position_back(t_coor coor, int y_decal,\
						int x_decal);
void					ft_update_position(t_coor coor, int y_decal,\
						int x_decal);

//FT_CHECKER.C
int						ft_checker_map(t_coor *coor);
int						ft_checker(t_coor *coor, int i, int j, int count);

//ALGO.C
void					ft_solve(t_coor *coor);
void					ft_surround_him(t_coor *coor, int i, int j, int count);
void					ft_fill_on_top(t_coor *coor);
void					ft_fill_on_top_as_possible(t_coor *coor);

#endif