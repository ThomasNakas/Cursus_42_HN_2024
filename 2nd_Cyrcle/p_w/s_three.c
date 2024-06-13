/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_three.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:32:36 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/05 20:33:38 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b, int c)
{
	return ((a * (a > b && a > c)) + (b * (b > a && b > c))
		+ c * (c > a && c > b));
}

void	sort_three(t_node **h)
{
	int	a;
	int	b;
	int	c;
	int	m;

	a = (*h)->n;
	b = (*h)->next->n;
	c = (*h)->next->next->n;
	m = max(a, b, c);
	if (m == c && a > b)
		s(h, 0);
	if (m == a)
	{
		r(h, 0);
		sort_three(h);
	}
	if (m == b)
	{
		rr(h, 0);
		sort_three(h);
	}
}
