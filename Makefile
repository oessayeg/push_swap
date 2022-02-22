NAME = push_swap

CHECKER = checker

FLAGS = -Wall -Wextra -Werror

SRCS = $(addsuffix .o, error_functions1 error_functions2 medium_stack2 push_swap \
small_stack2 stack_functions1 stack_functions2 stack_functions3 medium_stack3 \
small_stack1 calc_functions putfunctions some_functions medium_stack1)

C_SRCS = $(addsuffix .o, checker error_functions1 error_functions2 stack_functions3 \
		 stack_functions2 stack_functions1 medium_stack2 checker_utils)

all : $(NAME) $(CHECKER)

$(CHECKER) : $(C_SRCS)
	@gcc $(FLAGS) $(C_SRCS) libft/libft.a -o $(CHECKER)

$(NAME) : $(SRCS)
	@printf "\033[32;5m---------->Compiling<----------\033[0m\n"
	@make -C libft re
	@gcc $(FLAGS) $^ libft/libft.a -o $(NAME)
	@printf "\033[35;5mPush_Swap Compiled Succesfully !\033[0m\n" 

%.o : %.c
	@gcc $(FLAGS) -c $^

clean :
	@rm -f $(SRCS) $(C_SRCS)
	@make -C libft clean
	@printf "\033[31;5mObject Files Deleted !\033[0m\n"

fclean : clean
	@rm -f push_swap checker
	@make -C libft fclean
	@printf "\033[31;5mPush_Swap Program Deleted !\033[0m\n"

re : fclean all

.PHONY : all clean fclean re
