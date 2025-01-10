NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf 

SRC = main.c push_swap_utils.c more_utils.c movements.c\

OBJ = $(SRC:.c =.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "${CIAN}Compiling...${NC}"
	@$(CC) $(CFLAGS) $(OBJ)
	@echo "${LGREEN}Program compiled✅${NC}"

clean :
	@$(RM) $(OBJ)
	@echo "${MAGENTA}Objects deleted🧹${NC}"

fclean : clean
	@$(RM) $(NAME)
	@echo "${MAGENTA}All clean✨${NC}"

re : fclean all

.PHONY: all clean fclean re
