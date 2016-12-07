# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 07:52:25 by gudemare          #+#    #+#              #
#    Updated: 2016/12/07 08:13:22 by gudemare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
HFLAGS		=	-I includes/ -I libft/includes/
LFLAGS		=	-Llibft/ -lft

SRCS_DIR	=	srcs/
SRCS_LIST	=	\
				main.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./objs/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

.PHONY : all norme clean fclean re debug debug_re

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(HFLAGS) $(LFLAGS) $^ -o $@
	@printf "\e[32mProgram \e[1m$(NAME)\e[0m\e[32m has been compiled successfully !.\e[0m\n"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HFLAGS) $(LFLAGS) -c $< -o $@

norme :
	@if type "norminette" &> /dev/null ; then\
		printf "\e[34m\e[1mChecking Norm ...\e[s\n\e[0m" && \
		norminette **/*.[ch] | grep -v -B 1 "^Norme: " || printf "\e[u\e[$$(tput cols)C\e[11D\e[32m\e[7m[ NORME OK ]\e[21m\e[0m\n" ; \
	else\
		printf "\e[31mNorminette not installed, not checking norm.\e[$$(tput cols)C\e[8D\e[7m[ Error ]\n\e[21m\e[0m";\
	fi

clean :
	@rm -rf $(OBJS_DIR)
	@printf "\e[33mObjects files removed.\e[0m\n"
fclean : clean
	@rm -f $(NAME)
	@printf "\e[33mLibrary \e[1m$(NAME)\e[0m\e[33m removed.\e[0m\n"

re: fclean all

debug : CFLAGS=-Wall -Wextra -fsanitize=address -g
debug : norme all

debug_re : fclean debug
