# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 23:12:52 by yongmiki          #+#    #+#              #
#    Updated: 2022/02/16 22:15:31 by yongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minitalk

COMMON_INC_DIR		= ./include/
COMMON_SRC_DIR		= ./source/common/
COMMON_SRC_NAME		= print_message_common.c \
					  set_signal_common.c \
					  ft_strlen.c \
					  ft_isdigit.c \
					  ft_atoi.c \
					  ft_putendl_fd.c \
					  ft_putstr_fd.c \
					  ft_putnbr_fd.c \
					  ft_strlcpy.c \
					  ft_putchar_fd.c

COMMON_SRCS			= $(addprefix $(COMMON_SRC_DIR), $(COMMON_SRC_NAME))
COMMON_OBJS			= $(COMMON_SRCS:.c=.o)					  

CLIENT_NAME			= client
CLIENT_INC_DIR		= ./include/
CLIENT_SRC_DIR		= ./source/client/
CLIENT_SRC_NAME		= send_packet.c \
					  check_argument.c \
					  main.c
CLIENT_SRCS			= $(addprefix $(CLIENT_SRC_DIR), $(CLIENT_SRC_NAME))
CLIENT_OBJS			= $(CLIENT_SRCS:.c=.o)					  

SERVER_NAME			= server
SERVER_INC_DIR		= ./include/
SERVER_SRC_DIR		= ./source/server/
SERVER_SRC_NAME		= init_server_vars.c \
					  malloc_utility.c \
					  receive_packet.c \
					  print_message.c \
					  main.c
SERVER_SRCS			= $(addprefix $(SERVER_SRC_DIR), $(SERVER_SRC_NAME))
SERVER_OBJS			= $(SERVER_SRCS:.c=.o)					  

CC					= gcc
CFLAGS				= -Wall -Wextra -Werror 
INCDIR				= -I $(COMMON_INC_DIR)
INCDIR				+= -I $(CLIENT_INC_DIR)
INCDIR				+= -I $(SERVER_INC_DIR)

RM					= rm -f

.c.o:
					$(CC) $(CFLAGS) $(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):
					
					@make $(CLIENT_NAME)
					@make $(SERVER_NAME)

$(CLIENT_NAME):		$(COMMON_OBJS) $(CLIENT_OBJS)
					$(CC) $(CFLAGS) $(COMMON_OBJS) $(CLIENT_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME):		$(COMMON_OBJS) $(SERVER_OBJS)
					$(CC) $(CFLAGS) $(COMMON_OBJS) $(SERVER_OBJS) -o $(SERVER_NAME)

all:				$(NAME)

bonus:				$(NAME)

clean:
					$(RM) $(COMMON_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean:				clean
					$(RM) $(CLIENT_NAME)
					$(RM) $(SERVER_NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re
