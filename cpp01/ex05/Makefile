NAME		=	harl

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC			=	$(addprefix $(SRC_DIR), Harl.cpp main.cpp)
OBJ			=	$(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
INC			=	-I $(INC_DIR)

all:			$(NAME)

$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
						
clean:
				rm -rf $(OBJ_DIR)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
