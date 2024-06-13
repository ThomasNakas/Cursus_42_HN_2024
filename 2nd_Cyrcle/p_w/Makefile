# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 01:08:28 by tnakas            #+#    #+#              #
#    Updated: 2024/06/09 19:58:36 by tnakas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

SRC = push_swap.c h_err.c h_par.c h_ssplit.c \
		h_node_op_one.c h_node_op_two.c h_node_op_three.c h_node_op_four.c \
		h_node_five.c u_cmds_one.c u_cmds_two.c u_cmds_three.c u_srt.c \
		s_three.c s_five.c m_utils_one.c a_kpush_a_to_b.c

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[0;34m
RESET = \033[0m

%.o: %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf
	@echo "$(GREEN)Executable $(NAME) created successfully!$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "$(BLUE)Library libft created successfully!$(RESET)"

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR) > /dev/null
	@echo "$(BLUE)Library ft_printf created successfully!$(RESET)"

all: $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@$(MAKE) -C $(FT_PRINTF_DIR) clean > /dev/null
	@rm -f $(OBJ)
	@echo "$(YELLOW)Cleaned up object files and temporary files.$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean > /dev/null
	@rm -f $(NAME)
	@echo "$(RED)Fully cleaned including executable and libraries.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
