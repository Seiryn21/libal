NAME = libal.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/

SRC_FILES =	lst/al_lstadd.c \
			lst/al_lstdel.c \
			lst/al_lstget.c \
			lst/al_lstiter.c \
			lst/al_lstlen.c \
			lst/al_lstnew.c \
			lst/al_lsttoarray.c \
			math/mat4/al_mat4_init.c \
			math/mat4/al_mat4_lookat.c \
			math/mat4/al_mat4_mult_vec4.c \
			math/mat4/al_mat4_mult.c \
			math/mat4/al_mat4_print.c \
			math/mat4/al_mat4_projection.c \
			math/mat4/al_mat4_rotate.c \
			math/mat4/al_mat4_scale.c \
			math/mat4/al_mat4_translate.c \
			math/vec/al_vec_print.c \
			math/vec/al_vec3_add.c \
			math/vec/al_vec3_div.c \
			math/vec/al_vec3_init.c \
			math/vec/al_vec3_len.c \
			math/vec/al_vec3_mult.c \
			math/vec/al_vec3_norm.c \
			math/vec/al_vec3_product.c \
			math/vec/al_vec3_sub.c \
			math/vec/al_vec3_from_vec4.c \
			math/vec/al_vec4_from_vec3.c \
			math/al_abs.c \
			math/al_atoi.c \
			math/al_cos.c \
			math/al_pow.c \
			math/al_sin.c \
			math/al_sqrt.c \
			math/al_tan.c \
			mem/al_memalloc.c \
			mem/al_memcpy.c \
			mem/al_memdel.c \
			mem/al_memset.c \
			print/al_putchar.c \
			print/al_putline.c \
			print/al_putnbr.c \
			print/al_putstr.c \
			print/al_putfloat.c \
			regex/al_regcomp.c \
			regex/al_regfrag.c \
			str/al_strcat.c \
			str/al_strchr.c \
			str/al_strcmp.c \
			str/al_strcnt.c \
			str/al_strcpy.c \
			str/al_strdel.c \
			str/al_strdup.c \
			str/al_strequ.c \
			str/al_strjoin.c \
			str/al_strlen.c \
			str/al_strnew.c \
			str/al_strsplit.c \
			get_next_line.c

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
