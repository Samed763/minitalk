
client: client.c utils.c
	cc -Wall -Werror -Wextra client.c utils.c -o client

server: server.c utils.c
	cc -Wall -Werror -Wextra server.c utils.c -o server
