CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror
LDFLAGS		=		-ljansson
SRC_DIR		=		./src/
SRCS		=		$(wildcard $(SRC_DIR)*.c)
OBJ_DIR		=		./obj/
OBJ			=		$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all			:		app

app			:		$(OBJ)
					$(CC) $(LDFLAGS) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)		:
					mkdir -p $@

clean			:
					rm -rf $(OBJ_DIR)*.o
					rm -rf $(OBJ_DIR)


fclean			:	clean
					rm -rf app

re				:	fclean all

.PHONY			:	all clean fclean re

#leaks --atExit -- ./app

