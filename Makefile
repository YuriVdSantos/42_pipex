NAME = meu_programa

SRCDIR = src
INCDIR = include
LIBFTDIR = libft

SRC = $(SRCDIR)/main.c $(SRCDIR)/core_process.c $(SRCDIR)/pipex.c $(SRCDIR)/get_path.c $(SRCDIR)/split_cmd.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR)

# Biblioteca libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -lft -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all
