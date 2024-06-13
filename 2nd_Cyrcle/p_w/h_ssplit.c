/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_ssplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:58:56 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/09 12:20:35 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	words(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		words++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	if (words == 0)
		exit_message();
	return (words);
}

// // computing the length
int	word_len(const char *s, int start, char c)
{
	int	length;

	start--;
	length = 0;
	while (s[++start] && s[start] != c)
		length++;
	return (length);
}
// 3 4 2 500 -1 => soring them 1 2 3 4 5
//							   0 1 2 3 4
// 2 3 1 4 0
// 3 is the one that i m searching
// i  = 0  => ar[0] == 3 ?? no 
// i  = 1  => ar[1] == 3 ?? no
// i  = 2  => ar[2] == 3 ?? yes
// index = NULL;
// index = 2;
//============================
// 1 4 0 = a
// 2 3   = b
// // freeing the strings and the array|| we don't need
// to free for the current failed allocation

void	ft_free(char **s, int last)
{
	int	i;

	i = 0;
	while (last > 0)
	{
		free(s[last]);
		last--;
		i++;
	}
	free(s);
}

void	ft_free_push_swap(char **s, int last, int words)
{
	if (s[last] && words == 1 && is_valid_and_int(s[last]))
	{
		ft_free(s, last);
		exit (0);
	}
	ft_free(s, last);
	exit_message();
}
// // making the split

char	**split_improved(const char *s, char c)
{
	t_split	v;

	if (!s)
		return (NULL);
	v.i = 0;
	v.j = 0;
	v.w = words(s, c);
	v.res = (char **)malloc(sizeof(char *) * (v.w + 2));
	if (!v.res)
		return (NULL);
	v.res[0] = "a.out\0";
	while (++v.i <= v.w)
	{
		while (s[v.j] && s[v.j] == c)
			v.j++;
		v.res[v.i] = ft_substr(s, v.j, word_len(s, v.j, c));
		if (!v.res[v.i] || !is_valid_and_int(v.res[v.i]) || v.w == 1)
			ft_free_push_swap(v.res, v.i, v.w);
		v.j += word_len(s, v.j, c);
	}
	v.res[v.w + 1] = NULL;
	return (v.res);
}
