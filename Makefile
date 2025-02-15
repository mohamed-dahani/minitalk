SRCS_CLIENT = client.c \
	   helper-functions/ft_printf/ft_printf.c helper-functions/ft_printf/ft_putchar.c helper-functions/ft_printf/ft_putstr.c helper-functions/ft_printf/ft_putnbr.c helper-functions/ft_printf/convert_hexa.c helper-functions/ft_printf/convert_decimal.c helper-functions/custom_error.c helper-functions/ft_atoi.c

SRCS_SERVER = server.c \
	   helper-functions/ft_printf/ft_printf.c helper-functions/ft_printf/ft_putchar.c helper-functions/ft_printf/ft_putstr.c helper-functions/ft_printf/ft_putnbr.c helper-functions/ft_printf/convert_hexa.c helper-functions/ft_printf/convert_decimal.c helper-functions/custom_error.c helper-functions/ft_atoi.c


CLIENT_OBJS = $(SRCS_CLIENT:.c=.o)
SERVER_OBJS = $(SRCS_SERVER:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: client server

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o client $(CLIENT_OBJS)

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o server $(SERVER_OBJS)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	$(RM) client server

re: fclean all

.PHONY: all clean fclean re