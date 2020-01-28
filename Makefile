NAME = libal.a


CC = gcc
FLAGS		=	-Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/

SRC_FILES = str/al_strcat.c \
			str/al_strcpy.c \
			str/al_strdup.c \
			str/al_strlen.c \
			str/al_strnew.c \

SRCS  = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	@echo Make $(NAME)
	@ar -rc $(NAME) $(OBJS)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@mkdir $(dir $(OBJS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c  | $(OBJ_DIR)
	@echo Make $<
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

clean :
	@rm -rf $(NAME)

fclean : clean
	@rm -rf $(OBJ_DIR)

.PHONY: all clean fclean re
