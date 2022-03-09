# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 13:41:30 by yongmiki          #+#    #+#              #
#    Updated: 2022/03/09 21:06:20 by yongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_split.c ft_putstr_fd.c

SRCBONUS = 	ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c 

OBJBONUS = ${SRCBONUS:.c=.o}

OBJS = ${SRCS:.c=.o}

HEADER = libft.h

NAME = libft.a

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o:	%.c ${HEADER}
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@ar rc ${NAME} ${OBJS}

bonus:		${OBJBONUS}
			@ar rc ${NAME} ${OBJBONUS}

all:		${NAME}
			
clean:
			@${RM} ${OBJS} ${OBJBONUS}

fclean:		clean
			@${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re