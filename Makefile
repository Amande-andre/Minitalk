# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 16:47:31 by anmande           #+#    #+#              #
#    Updated: 2023/02/12 14:38:44 by anmande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= ./client/client

SERVER		= ./server/server

B_CLIENT	= ./b_client/bonus_client 

B_SERVER	= ./b_server/bonus_server 

LIBDIR		= libft/libft.a

LIBDIRP		= ./libft		

B_SRC_CLIENT = ./b_client/client.c

B_SRC_SERVER = ./b_server/server.c

SRC_CLIENT	= ./client/client.c \

SRC_SERVER	= ./server/server.c \

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

B_OBJ_SERVER = $(B_SRC_SERVER:.c=.o)

B_OBJ_CLIENT = $(B_SRC_CLIENT:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Wextra -I./include/

RM			= rm -f

all:		$(CLIENT) $(SERVER)

$(SERVER):	$(OBJ_SERVER) $(LIBDIR)
		$(CC) -o $(SERVER) $(OBJ_SERVER) $(LIBDIR)

$(CLIENT):	$(OBJ_CLIENT) $(LIBDIR)
		$(CC) -o $(CLIENT) $(OBJ_CLIENT) $(LIBDIR)

$(B_SERVER): $(B_OBJ_SERVER) $(LIBDIR)
		$(CC) -o $(B_SERVER) $(B_OBJ_SERVER) $(LIBDIR)

$(B_CLIENT): $(B_OBJ_CLIENT) $(LIBDIR)
		$(CC) -o $(B_CLIENT) $(B_OBJ_CLIENT) $(LIBDIR)

bonus:	$(B_SERVER) $(B_CLIENT) 

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) 
		make clean -s -C $(LIBDIRP)

fclean:		clean
		$(RM) $(SERVER) $(CLIENT) $(B_SERVER) $(B_CLIENT)

re:		fclean all

.PHONY: all clean fclean re bonus
