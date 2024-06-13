/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_srt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:40:03 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/05 20:04:21 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_bubble_sorting(int *a, int sz)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < sz)
	{
		j = i;
		while (++j < sz)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void	array_indexing(int *a, int *b, int sz)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sz)
	{
		j = -1;
		while (++j < sz)
		{
			if (a[i] == b[j])
			{
				a[i] = j;
				break ;
			}
		}
	}
}

int	*array_dup(int *src, int sz)
{
	int	*dest;
	int	i;

	i = -1;
	dest = (int *)malloc(sizeof(int) * (sz + 1));
	if (!dest)
		return (free(dest), NULL);
	while (++i < sz)
		dest[i] = src[i];
	return (dest);
}

void	array_comb(int	*a, int sz)
{
	int	*b;

	b = array_dup(a, sz);
	if (!b)
		return ;
	array_bubble_sorting(b, sz);
	array_indexing(a, b, sz);
	free(b);
}
