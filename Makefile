NAME = libal.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/

SRC_FILES = lst/al_lstadd.c \
			lst/al_lstdel.c \
			lst/al_lstget.c \
			lst/al_lstiter.c \
			lst/al_lstlen.c \
			lst/al_lstnew.c \
			mem/al_memalloc.c \
			mem/al_memcpy.c \
			mem/al_memdel.c \
			print/al_putchar.c \
			print/al_putline.c \
			print/al_putnbr.c \
			print/al_putstr.c \
			str/al_strcat.c \
			str/al_strchr.c \
			str/al_strcmp.c \
			str/al_strcpy.c \
			str/al_strdel.c \
			str/al_strdup.c \
			str/al_strequ.c \
			str/al_strlen.c \
			str/al_strnew.c \

SRCS  = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@echo Make $(NAME)
	@ar -rc $(NAME) $(OBJS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo Make $<
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

clean :
	@rm -rf $(NAME)

fclean : clean
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
