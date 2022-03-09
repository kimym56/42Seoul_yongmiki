# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:04:00 by yongmiki          #+#    #+#              #
#    Updated: 2022/03/09 21:09:51 by yongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-I includes

NAME	=	push_swap

SRCS_NAME	=	push_swap.c checks.c utils.c opt_swap_push.c opt_rotate.c \
				lib_modif.c little_sort.c lst_utils.c main_algo.c algo_utils.c


SRC_PATH	=	srcs/push_swap_srcs

LIBFT       =	srcs/libft/libft.a

SRCS		=	$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

OBJ	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ${SRC_PATH}/push_swap.h
	@make -C srcs/libft
	@make -C srcs/libft bonus
	@echo "Making Libft..."
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LIBFT)
	@echo "Making push_swap..."

%.o : %.c	
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@make -C srcs/libft clean
	@echo "Clean(libft)"
	@echo "Clean(push_swap)"

fclean: clean
	@rm -f $(NAME)
	@make -C srcs/libft fclean
	@echo "Fclean(libft)"
	@echo "Fclean(push_swap)"

re : fclean all

.PHONY: all fclean clean re $(EXEC)