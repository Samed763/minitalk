CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
SERVER = server.c
CLIENT = client.c
NAME = minitalk

SERVER_BONUS = server_bonus.c
CLIENT_BONUS = client_bonus.c
UTILS = utils.c


all: $(NAME)

$(NAME): server client

server: $(SERVER)
	$(CC) $(FLAGS) $(UTILS) $(SERVER) -o server

client: $(CLIENT)
	$(CC) $(FLAGS) $(UTILS) $(CLIENT) -o client

bonus: server_bonus client_bonus

server_bonus:$(SERVER_BONUS)
	$(CC) $(FLAGS) $(UTILS) $(SERVER_BONUS) -o server_bonus

client_bonus:$(CLIENT_BONUS)
	$(CC) $(FLAGS) $(UTILS) $(CLIENT_BONUS) -o client_bonus

clean:
	$(RM) client server server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re bonus