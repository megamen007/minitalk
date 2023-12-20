CC = gcc

CFLAGS = -Wall -Wextra -Werror

CLIENT_SRC = client.c minitalk_utils1.c minitalk_utils2.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

NAME_CLIENT = client

SERVER_SRC = server.c minitalk_utils1.c minitalk_utils2.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)

NAME_SERVER = server

CLIENT_BONUS_SRC = client_bonus.c minitalk_utils1.c minitalk_utils2.c

CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

NAME_CLIENT_BONUS = client_bonus 

SERVER_BONUS_SRC = server_bonus.c minitalk_utils1.c minitalk_utils2.c

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

NAME_SERVER_BONUS = server_bonus 

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(SERVER_BONUS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -o $(NAME_SERVER_BONUS)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

clean:
		rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)

fclean : clean
		rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re: fclean all

.PHONY: re fclean clean 