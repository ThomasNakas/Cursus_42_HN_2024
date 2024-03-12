/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:41:54 by tnakas            #+#    #+#             */
/*   Updated: 2024/03/10 20:19:28 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_subs(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			counter++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (counter);
}

static size_t	sub_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	free_memory(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, sub_len(&*(s + j), c));
		if (!*(array + i))
		{
			free_memory(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	subs;

	if (!s)
		return (NULL);
	subs = count_subs(s, c);
	arr = (char **)malloc(sizeof(char *) * (subs + 1));
	if (!arr)
		return (NULL);
	return (split(s, c, arr, subs));
}
