# program name
NAME		=	brain

# compiler and flags
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# source and object files
SRC			=	main.cpp
OBJ			=	$(SRC:.cpp=.o)

# colors
RESET		= \033[0m
RED			= \033[0;31m
YELLOW		= \033[0;33m
GREEN_BOLD	= \033[1;32m

# rules
all:			$(NAME)

$(NAME):		$(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					@echo "$(GREEN_BOLD)$(NAME) compiled successfully!$(RESET)"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)[compiling]$(RESET) $@"
						
clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
