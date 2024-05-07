# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 16:40:40 by tnakas            #+#    #+#              #
#    Updated: 2024/04/26 04:12:02 by tnakas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRS			= ft_itoa.c ft_strlen.c ft_atoi.c ft_strjoin.c ft_strdup.c ft_calloc.c ft_bzero.c
OBJS			= $(SCRS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus
