NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f
SRCS = ft_printf.c \
		ft_printf_utils1.c \
		ft_printf_utils2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re:
	make fclean
	make all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^

.PHONY: all clean f