# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/07/13 14:52:01 by fholwerd      #+#    #+#                  #
#    Updated: 2022/11/08 13:16:03 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= pipex
SRC		= $(ROOT)src/main.c \
			$(ROOT)src/pipex.c \
			$(ROOT)src/parse.c \
			$(ROOT)src/check_cmd_path.c \
			$(ROOT)src/child_process.c \
			$(ROOT)src/struct_tools.c \
			$(ROOT)src/utils/ft_strdup.c \
			$(ROOT)src/utils/ft_strncmp.c \
			$(ROOT)src/utils/ft_strlen.c \
			$(ROOT)src/utils/ft_strjoin.c \
			$(ROOT)src/utils/ft_split.c \
			$(ROOT)src/utils/stop.c
OBJ		= $(SRC:.c=.o)
INCLUDE	= -I$(ROOT)include \
			-I$(ROOT)include/utils
CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "Compiling executable."
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all libs clean fclean re