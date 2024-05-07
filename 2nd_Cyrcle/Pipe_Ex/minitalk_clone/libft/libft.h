/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:45:35 by tnakas            #+#    #+#             */
/*   Updated: 2024/04/26 04:12:17 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

char		*ft_itoa(int n);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
char		*ft_strjoin_c(char *s1, char c, int len);
char		*ft_strdup(char *s1);
void		*ft_calloc(size_t count, size_t n);
void		ft_bzero(void *str, size_t n);
#endif
