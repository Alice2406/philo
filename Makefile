# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:25:39 by aniezgod          #+#    #+#              #
#    Updated: 2023/03/29 10:33:17 by aniezgod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ----------------------------------COLORS------------------------------------#

BOLD = \e[1;37m
END = \e[0;37m
UNDER = \e[4;37m
GREY = \e[0;30m
RED = \e[0;31m
GREEN = \e[0;32m
YELLOW = \e[0;33m
BLUE = \e[0;34m
PURPLE = \e[0;35m
CYAN = \e[0;36m
WHITE = \e[0;37m

SRCS =	./srcs/main.c \
		./srcs/init.c \
		./srcs/ft_error.c \
		./srcs/time.c \
		./srcs/routine.c \
		./srcs/ft_dead.c \
		./srcs/utils.c \

OBJS = ${SRCS:.c=.o}

NAME = philo
INCS = ./includes
CFLAGS = -Wall -Wextra -Werror -g -I $(INCS) -pthread
RM = rm -f
CC = gcc

all: ${NAME}

$(NAME): $(OBJS)
			@printf "${WHITE}${BOLD}╔════════════════════════════════════════════════════════════════════════════╗\n"
			@printf "${BOLD}║                              .: COMPILATION :.                             ║\n"
			@printf "${BOLD}╚════════════════════════════════════════════════════════════════════════════╝\n"
			@$(CC) ${CFLAGS} $(OBJS) -o $(NAME)
			@printf "${BOLD}║                                   ${PURPLE}${NAME}                                    ${WHITE}║\n"
			@printf "${BOLD}╚════════════════════════════════════════════════════════════════════════════╝\n"

clean:
			@${RM} ${OBJS}
			
fclean: clean
			@printf "${BOLD}Entreprise de nettoyage bonjour ?\n"
			@${RM} ${NAME}
			@printf "${BOLD}${GREEN}Tout est propre !✨\n"

re: fclean all

.PHONY:		all clean fclean re