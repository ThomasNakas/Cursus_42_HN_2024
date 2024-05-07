/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 01:50:14 by tnakas            #+#    #+#             */
/*   Updated: 2024/04/26 04:13:52 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (*(str + (++i)) != '\0')
		;
	return (i);
}

char	*ft_strjoin_c(char *s1, char c, int len)
{
	char	*res;
	int		i;

	if (!s1 && c != '\0')
	{
		res = (char *)malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = c;
		res[1] = '\0';
		return (res);
	}
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = c;
	res[++i] = '\0';
	return (res);
}
