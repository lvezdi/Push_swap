NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f 

SRC =  main.c str_utils.c num_utils.c error_utils.c operations.c processing.c indexing.c stack_utils.c sorting_algorithms.c basic_sorting.c\

LIB = Libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "${CIAN}Compiling...${NC}"
	@$(MAKE) -C Libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "${LGREEN}Program compiled✅${NC}"

clean :
	@$(MAKE) clean -C Libft
	@$(RM) $(OBJ)
	@echo "${MAGENTA}Objects deleted🧹${NC}"

fclean : clean
	@$(MAKE) fclean -C Libft
	@$(RM) $(NAME)
	@echo "${MAGENTA}All clean✨${NC}"

re : fclean all

.PHONY: all clean fclean re
