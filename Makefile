# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 16:11:46 by dzheng            #+#    #+#              #
#    Updated: 2017/02/18 18:00:51 by dzheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dzheng.filler
FLAG = -Wall -Werror -Wextra
LIB = ./libft/libft.a
SRCS_NAME = ft_filler.c \
			ft_get_data.c \
			ft_get_coordinates.c \
			ft_checker.c \
			ft_fill_when_you_can.c \
			ft_solve.c
SRC_PATH = srcs/
SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))

#COLORS
C_GREEN			=	"\033[32m"
C_END			= 	"\033[0m"

#MESSAGE
SUCCESS			=	SUCCESS$(C_END)

all: $(NAME)

$(NAME): 
	@make -C ./libft/
	@cc $(FLAG) $(SRCS) $(LIB) -o $(NAME)
	@echo $(C_GREEN)"Compiling" [ dzheng.filler ] $(SUCCESS)

cc:
	@cc $(FLAG) $(SRCS) $(LIB) -o $(NAME)
	@echo $(C_GREEN)"Compiling without flags" [ dzheng.filler ] $(SUCCESS)
	hilite ./resources/filler_vm -f ./resources/maps/map00 \
	-p1	./resources/players/carli.filler \
	-p2 ./dzheng.filler | ./Show_Filler/show.filler

clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

##-------------------TODO-------------------##

#SEGFAULT
#./dzheng.filler
#Piece [NO INFORMATION] after

##--------------- Map 00 ---------------##
## champely ==> Ne fait rien			##
## superjeannot ==> You WIN				##
## grati ==> You WIN EASY				##
## abanlin ==> You WIN mais une 9/10	##
## hcao ==> You WIN EASYY				##
## carli ==> C'est tendu sur la map00	##
