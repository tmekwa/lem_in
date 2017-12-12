# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tntoampe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 16:52:56 by tntoampe          #+#    #+#              #
#    Updated: 2017/11/30 13:15:13 by tntoampe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

INC = -L libft -lft

SRC = main.c \
	  lem_in.c \
	  path.c \
	  free.c \
	  ants.c \
	  move_ants.c \
	  printing.c

OBJ = 	$(SRC:%.c=%.o)

FLAGS = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		make -C libft 
		$(FLAGS) $(SRC) $(INC) -o $(NAME)
		ar rc $(OBJ) 

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean:
	make -C libft clean
	rm -f $(NAME)

re: fclean all
