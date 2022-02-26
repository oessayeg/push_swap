NAME = push_swap

CHECKER = checker

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix srcs/, error_functions1.c error_functions2.c medium_stack2.c push_swap.c \
small_stack2.c stack_functions1.c stack_functions2.c stack_functions3.c medium_stack3.c \
small_stack1.c calc_functions.c putfunctions.c some_functions.c medium_stack1.c)

C_SRCS = bonus_srcs/checker.c bonus_srcs/checker_utils.c srcs/error_functions1.c srcs/error_functions2.c srcs/stack_functions3.c \
		 srcs/stack_functions2.c srcs/stack_functions1.c srcs/medium_stack2.c

all : $(NAME) $(CHECKER)

$(CHECKER) : $(C_SRCS)
	@gcc $(FLAGS) $(C_SRCS) libft/libft.a -o $(CHECKER)

$(NAME) : $(SRCS)
	@printf "\033[32;5m---------->Compiling<----------\033[0m\n"
	@make -C libft re
	@gcc $(FLAGS) $^ libft/libft.a -o $(NAME)
	@printf "\033[35;5mPush_Swap Compiled Succesfully !\033[0m\n" 

clean :
	@make -C libft clean
	@printf "\033[31;5mObject Files Deleted !\033[0m\n"

fclean : clean
	@rm -f push_swap checker
	@make -C libft fclean
	@printf "\033[31;5mPush_Swap Program Deleted !\033[0m\n"

re : fclean all

.PHONY : all clean fclean re
