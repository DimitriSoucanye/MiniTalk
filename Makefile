##
## Makefile for a in /home/soucan_d/soucan_d/Projets/PSU_2015_minitalk
## 
## Made by Dimitri
## Login   <soucan_d@epitech.net>
## 
## Started on  Mon Feb  1 17:47:48 2016 Dimitri
## Last update Thu Feb 11 13:03:19 2016 Dimitri
##

CLIENT_NAME		= client/client

SERVER_NAME		= server/server

CLIENT_SRC		= client/main.c \
			  client/fonctions.c \
			  client/my_atoi.c \
			  client/my_putnbr_base.c

SERVER_SRC		= server/main.c \
			  server/tools.c \
			  server/exponen.c

CLIENT_OBJ		= $(CLIENT_SRC:.c=.o)

SERVER_OBJ		= $(SERVER_SRC:.c=.o)

all:			$(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ)
		cc $(CLIENT_OBJ) -o $(CLIENT_NAME)


$(SERVER_NAME): $(SERVER_OBJ)
		cc $(SERVER_OBJ) -o $(SERVER_NAME)

clean:
		rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
		rm -f client/client server/server

re:     fclean all

.PHONY: all clean fclean re
