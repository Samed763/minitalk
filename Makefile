CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c utils.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: client server clean_objs

client: $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o client

server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o server

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean_objs:
	rm -f *.o

clean:
	rm -f *.o client server

.PHONY: all clean clean_objs
