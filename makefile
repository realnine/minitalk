
SERVER = server

CLIENT = client

CC = gcc -Wall -Werror -Wextra

RM = rm -rf

LIBFT = libft.a

LIB_DIR = ./libft/


all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) :
	$(MAKE) -C $(LIB_DIR)

$(SERVER) : 
	$(CC) server.c -o $@ -L$(LIB_DIR) -lft

$(CLIENT) : 
	$(CC) client.c -o $@ -L$(LIB_DIR) -lft

clean :
	$(MAKE) clean -C $(LIB_DIR)
	$(RM) *.o

fclean : clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(SERVER) $(CLIENT)

.PHONY : all clean fclean
