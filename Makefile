# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 16:11:46 by dzheng            #+#    #+#              #
#    Updated: 2017/02/22 18:58:12 by dzheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dzheng.filler
FLAG = -Wall -Werror -Wextra
LIB = ./libft/libft.a
SRCS_NAME = main.c \
			ft_get_data_coor.c \
			ft_get_data_pc.c \
			ft_check_if_fit.c \
			ft_filler.c \
			ft_strat_print.c
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
	@cc -g $(FLAG) $(SRCS) $(LIB) -o $(NAME)
	@echo $(C_GREEN)"Compiling without flags" [ dzheng.filler ] $(SUCCESS)
	hilite ./resources/filler_vm -f ./resources/maps/map01 \
	-p1	./resources/players/hcao.filler \
	-p2 ./dzheng.filler

##-------------------TODO-------------------##
#SEGFAULT
#./dzheng.filler
#Piece [NO INFORMATION] after
#Protection ac des Strlen ! if strlen de "piece " < piece [3 , 9]
#Erreur de la VM et eviter le segfault

##--------------------GRAPH-----------------##
#| ./Show_Filler/show.filler

##------------------Map 00------------------##
## champely ==> Ne fait rien				##
## superjeannot ==> You WIN					##
## grati ==> You WIN EASY					##
## abanlin ==> You WIN mais une 9/10		##
## hcao ==> You WIN EASYY					##
## carli ==> C'est tendu sur la map00		##

clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

