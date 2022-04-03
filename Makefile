# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 11:22:27 by yongmiki          #+#    #+#              #
#    Updated: 2022/04/03 18:34:04 by yongmiki         ###   ########.fr        #
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