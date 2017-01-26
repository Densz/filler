# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 16:11:46 by dzheng            #+#    #+#              #
#    Updated: 2017/01/26 16:48:16 by dzheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dzheng.filler
FLAG = -Wall -Werror -Wextra
LIB = ./ft_printf/libftprintf.a
SRCS_NAME = ft_filler.c \
			ft_get_data.c \
			ft_get_coordinates.c \
			ft_algo.c
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
	hilite ./resources/filler_vm -f ./resources/maps/map00 -p2 ./resources/players/carli.filler -p1 ./dzheng.filler

clean:
	@make -C ./ft_printf/ clean

fclean: clean
	@#make -C ./ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re