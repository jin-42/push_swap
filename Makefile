# Variable Names
EXEC = push_swap
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDE_DIRS = -I include/ -I ft_libft/include/

SOURCES = src/algo.c    src/parsing_utils.c  src/reverse_rotate.c  src/sort.c \
src/algo_utils.c  src/list_utils.c  src/parsing.c     src/push.c           src/rotate.c          src/swap.c

# Object Files
CLIENT_OBJ = $(SOURCES:.c=.o)

# Library
FT_LIBFT = ft_libft/libft.a

# Targets
all: $(EXEC) $(FT_LIBFT)

$(EXEC): $(CLIENT_OBJ) $(FT_LIBFT) include/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CLIENT_OBJ) $(FT_LIBFT) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

ft_libft/libft.a: FORCE
	@make -C ft_libft

# Clean Targets
clean:
	rm -f $(CLIENT_OBJ)
	make clean -C ft_libft

# Force Rebuild
FORCE:

# Full Clean
fclean: clean
	rm -f $(EXEC)
	make fclean -C ft_libft

# Rebuild
re: fclean all

# Phony Targets
.PHONY: all clean fclean re FORCE
