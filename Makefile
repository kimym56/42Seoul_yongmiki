# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 11:22:27 by tom               #+#    #+#              #
#    Updated: 2022/04/03 01:07:14 by yongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS
CFLAGS = -Wall -Wextra -Werror

# EXECUTABLE
NAME = ./philo

# PATHS
SRC_PATH = ./src/

# SOURCES
SRC =	$(SRC_PATH)utils/common.c $(SRC_PATH)utils/utils.c $(SRC_PATH)main.c \
		$(SRC_PATH)input.c $(SRC_PATH)routine.c	\

# OBJECTS
OBJ = $(SRC:.c=.o)

# RULES
all: $(NAME)

$(NAME): $(OBJ)
	@cc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f -r $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re