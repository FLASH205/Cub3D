NAME = cub3D

FLAG = -Wextra -Werror -Wall -fsanitize=address -g

MLX = -lmlx -framework OpenGL -framework AppKit

SRC = \
	main.c \
	ft_clean_all.c \
	get_next_line.c \
	get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAG) $(OBJ) $(MLX) -o $@

%.o : %.c cub3d.h
	cc $(FLAG) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
