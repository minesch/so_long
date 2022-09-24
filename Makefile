NAME = so_long
CC = cc
OBJS_DIR = objs
SRCS_DIR = src
INCLUDES = -Iincludes -Imlx
FLAGS = -Wall -Werror -Wextra -g -ggdb3 $(INCLUDES)
LINKERS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.dylib
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
MLX_OBJS = $(wildcard $(MLX_DIR)/*.o)
RM = rm -rf
MKDIR = mkdir -p

.DEFAULT_GOAL = all

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX_LIB) $(OBJS) | $(OBJS_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LINKERS)

bonus: all

clean:
	$(RM) $(MLX_OBJS) $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

push:
	@git add .
	@git commit -m "$m"
	@git push

.PHONY: all clean fclean re bonus push
