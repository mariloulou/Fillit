# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 07:52:25 by gudemare          #+#    #+#              #
#    Updated: 2016/12/08 14:00:56 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
HFLAGS		=	-I ./includes/ -I libft/includes/
LFLAGS		=	-L./libft/ -lft

SRCS_DIR	=	./srcs/
SRCS_LIST	=	\
				main.c \
				fillit.c \
				parse_input.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./objs/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

LIB			=	./libft/libft.a
LIB_DIR		=	./libft/

.PHONY : all norme clean fclean re debug debug_re test

all: $(LIB) $(NAME)

$(LIB) :
	@cd $(LIB_DIR) && make

$(NAME) : $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(HFLAGS) $(OBJS) $(LFLAGS) -o $@
	@printf "\e[32mProgram \e[1m$(NAME)\e[0m\e[32m successfully compiled.\e[0m\n"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

norme :
	@if type "norminette" &> /dev/null ; then\
		printf "\e[34m\e[1mChecking Norm ...\e[s\n\e[0m" && \
		norminette **/*.[ch] | grep -v -B 1 "^Norme: " || printf "\e[u\e[$$(tput cols)C\e[11D\e[32m\e[7m[ NORME OK ]\e[21m\e[0m\n" ; \
	else\
		printf "\e[31mNorminette not installed, not checking norm.\e[$$(tput cols)C\e[8D\e[7m[ Error ]\n\e[21m\e[0m";\
	fi

test : all
	@printf "===========================[ Input Validation Tests ]===========================\n"
	@printf "Valid inputs : "
	@./fillit test/valid-1.fillit &>/dev/null && printf "\e[32m.\e[0m" || printf "\e[31mF\e[0m"
	@./fillit test/valid-2.fillit &>/dev/null && printf "\e[32m.\e[0m" || printf "\e[31mF\e[0m"
	@./fillit test/valid-3.fillit &>/dev/null && printf "\e[32m.\e[0m" || printf "\e[31mF\e[0m"
	@./fillit test/valid-4.fillit &>/dev/null && printf "\e[32m.\e[0m" || printf "\e[31mF\e[0m"
	@printf "\nInvalid format : "
	@./fillit test/invalid-1.fillit &>/dev/null && printf "\e[31mF\e[0m" || printf "\e[32m.\e[0m"
	@./fillit test/invalid-2.fillit &>/dev/null && printf "\e[31mF\e[0m" || printf "\e[32m.\e[0m"
	@./fillit test/invalid-3.fillit &>/dev/null && printf "\e[31mF\e[0m" || printf "\e[32m.\e[0m"
	@./fillit test/invalid-4.fillit &>/dev/null && printf "\e[31mF\e[0m" || printf "\e[32m.\e[0m"
	@./fillit test/invalid-5.fillit &>/dev/null && printf "\e[31mF\e[0m" || printf "\e[32m.\e[0m"
	@printf "\nInvalid tetriminos : "
	@./fillit test/invalid-6.fillit &>/dev/null && printf "\e[31mF\e[0m" || printf "\e[32m.\e[0m"
	@./fillit test/invalid-7.fillit &>/dev/null && printf "\e[31mF\e[0m" || printf "\e[32m.\e[0m"
	@./fillit test/invalid-8.fillit &>/dev/null && printf "\e[31mF\e[0m" || printf "\e[32m.\e[0m"
	@printf "\n=================================[ End Tests ]==================================\n"

Clean :
	@rm -rf $(OBJS_DIR)
	@cd $(LIB_DIR) && make clean
	@printf "\e[33m$(NAME)'s objects files have been removed.\e[0m\n"
fclean :
	@rm -rf $(NAME) $(OBJS_DIR)
	@cd $(LIB_DIR) && make fclean
	@printf "\e[33mProgram \e[1m$(NAME)\e[0m\e[33m and its objects files have been removed.\e[0m\n"

re: fclean all

debug : CFLAGS=-Wall -Wextra -fsanitize=address -g
debug : norme all

debug_re : fclean debug
