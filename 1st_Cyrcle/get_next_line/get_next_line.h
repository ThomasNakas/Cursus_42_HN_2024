/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:14:03 by tnakas            #+#    #+#             */
/*   Updated: 2024/04/17 19:31:33 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//==================BUFFER-SIZE=============================
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif
//=============GET NEXT LINE FUNCTIONS======================
char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int length);
char	*ft_strjoin(char *s1, char *s2, int len);
int		ft_linelen(char *str);
int		ft_str_bs(char *str, char c);
int		ft_strlen(const char *str);
char	*get_res(int fd, char *rem);

#endif