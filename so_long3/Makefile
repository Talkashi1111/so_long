NAME := so_long
OBJECT_DIR := obj
LIBFT_DIR := libft
INCLUDE_DIR := includes
SRC_DIR := srcs
FILES := main.c \
		map_valid.c \
		utils.c	\
		prepare_game.c \
		load_xpms.c \
		close_display.c \
		move_enemy_utils.c \
		frame_animation_update.c \
		render_graphics_helper.c \
		movement_update_tools.c \
		init_game.c \
		render_utils.c \
		control_keys.c \
		init_enemy.c \
		chars_valid.c \
		pars_and_free_map.c \
		check_if_map_solvable.c \
		map_surrounded_by_walls.c
SRCS := $(addprefix $(SRC_DIR)/, $(FILES))
TESTER := tests/big.ber
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	MINILIBX_DIR := minilibx-macos
	MLX_PATH := $(MINILIBX_DIR)/libmlx.dylib
	LFLAGS := -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework Appkit -lz -L$(LIBFT_DIR) -lft
	LEAK_TOOL := leaks -atExit --
else
	MINILIBX_DIR := minilibx-linux
	MLX_PATH := $(MINILIBX_DIR)/libmlx.a
	LFLAGS := $(MLX_PATH) -lX11 -lXext -L$(LIBFT_DIR) -lft
	LEAK_TOOL := valgrind --leak-check=full
endif

CFLAGS := -Wall -Wextra -Werror -g
IFLAGS := -I$(MINILIBX_DIR) -I$(LIBFT_DIR) -I$(INCLUDE_DIR)
#LFLAGS := -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -L$(LIBFT_DIR) -lft
OBJECTS := $(addprefix $(OBJECT_DIR)/,$(FILES:.c=.o))
CC := gcc

.PHONY: all 
all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_DIR)/libft.a $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJECTS) $(LFLAGS) -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_PATH):
	$(MAKE) -C $(MINILIBX_DIR)
	cp $(MLX_PATH) .

$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJECT_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ 

.PHONY: re
re: fclean all

.PHONY: clean
clean:
	rm -rf $(OBJECT_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	rm -f libmlx.dylib
	rm -f libmlx.a

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: test
test: $(NAME)
	./$(NAME) ./$(TESTER)

.PHONY: leak
leak: $(NAME)
	$(LEAK_TOOL) ./$(NAME) ./$(TESTER)

