NAME = server client
LIB = ./ft_printf/libftprintf.a
SRCSERVER = server.c
SRCCLIENT = client.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

all : $(LIB) $(NAME)

$(LIB):
	make -C ./ft_printf

$(NAME) : $(OBJSERVER) $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o client $(LIB)
	$(CC) $(OBJSERVER) -o server $(LIB)

clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT)

fclean: clean
	rm -rf server client

ffclean: fclean
	make fclean -C ./ft_printf

re:ffclean all

.PHONY : re fclean clean all ffclean