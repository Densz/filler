# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 16:11:46 by dzheng            #+#    #+#              #
#    Updated: 2017/01/27 16:13:20 by dzheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dzheng.filler
FLAG = -Wall -Werror -Wextra
LIB = ./ft_printf/libftprintf.a
SRCS_NAME = ft_filler.c \
			ft_get_data.c \
			ft_get_coordinates.c \
			ft_checker.c \
			ft_fill_when_you_can.c \
			ft_fill_on_top.c \
			ft_solve.c
SRC_PATH = srcs/
SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))

#COLORS
C_GREEN			=	"\033[33m"
C_END			= 	"\033[0m"

#MESSAGE
SUCCESS			=	SUCCESS$(C_END)

all: $(NAME)

$(NAME): 
	@make -C ./ft_printf/
	@cc $(FLAG) $(SRCS) $(LIB) -o $(NAME)
	@echo $(C_GREEN)"Compiling" [ dzheng.filler ] $(SUCCESS)

exe:
	@cc $(FLAG) $(SRCS) $(LIB) -o $(NAME)
	@echo $(C_GREEN)"Compiling without flags" [ dzheng.filler ] $(SUCCESS)
	hilite ./resources/filler_vm -f ./resources/maps/map00 -p1 ./resources/players/carli.filler -p2 ./dzheng.filler

clean:
	@make -C ./ft_printf/ clean

fclean: clean
	@#make -C ./ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re