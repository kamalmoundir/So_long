NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fPIE

LIBFT = library/libft/libft.a
FT_PRINTF = library/ft_printf/libftprintf.a

LIBRARY := -Llibrary/minilibx-linux -lmlx -lX11 -lXext -lm -lz
MINILIBX := library/minilibx-linux/

SRC_DIR = src/
SRC_FILES = fun_validate_map.c function_act.c functions_utiles.c \
            get_next_line_utils.c get_next_line.c load_graph.c player_act.c \
            so_long.c validate_map.c window.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(SRC:.c=.o)
INCLUDE = -I./include/ -I$(MINILIBX)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX)libmlx.a $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBRARY) $(LIBFT) $(FT_PRINTF) $(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
$(MINILIBX)libmlx.a:
	@make -C $(MINILIBX)
$(LIBFT):
	@make -C library/libft/
$(FT_PRINTF):
	@make -C library/ft_printf/


clean:
	$(RM) $(OBJS)
	@make clean -C library/libft/
	@make clean -C library/ft_printf/
	@make clean -C library/minilibx-linux/

fclean: clean
	$(RM) $(NAME)
	@make fclean -C library/libft/
	@make fclean -C library/ft_printf/
	@make fclean -C library/minilibx-linux/

re: fclean all

.PHONY: all clean fclean re
