# Nom de l'exécutable
EXEC = push_swap

# Compilateur
CC = gcc -g3

RM = rm -f
# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Répertoires d'inclusion
INCLUDE_DIRS = -I include/ -I ft_libft/include/

# Fichiers source
SRCS = list_utils.c parsing_utils.c parsing.c push.c reverse_rotate.c rotate.c swap.c

# Bibliothèque statique ft_libft
FT_LIBFT = ft_libft/libft.a

# Fichiers objets
OBJS = $(SRCS:.c=.o)

all: $(EXEC) $(FT_LIBFT)

$(EXEC): $(OBJS) $(FT_LIBFT) 
    	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $(EXEC)

# Règle générique pour la compilation des fichiers source en objets
%.o: %.c
    $(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

ft_libft/libft.a: FORCE
	@make -C ft_libft

clean : 
	rm -f $(OBJS)
	$(MAKE) clean -C ft_libft

FORCE:

# Nettoyage de l'exécutable et des fichiers objets
fclean: clean
    $(RM) $(EXEC)
    $(MAKE) fclean -C ft_libft 

# Règle pour reconstruire
re: fclean all

# Marque les cibles comme des cibles phony
.PHONY: all clean fclean re FORCE
