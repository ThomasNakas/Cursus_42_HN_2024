# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 01:08:28 by tnakas            #+#    #+#              #
#    Updated: 2024/04/25 01:22:23 by tnakas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

CLIENT_SRC = client.c
SERVER_SRC = server.c

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: client server

client: $(CLIENT_SRC) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

server: $(SERVER_SRC) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRC) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f client server

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
