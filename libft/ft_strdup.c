/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:48:29 by tnakas            #+#    #+#             */
/*   Updated: 2024/03/10 14:18:20 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*dest;
	int			i;
	int			j;

	i = 0;
	while (*(s1 + i))
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	j = -1;
	while (s1[++j])
		*(dest + j) = *(s1 + j);
	*(dest + j) = '\0';
	return (dest);
}
