/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_cmds_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:26:54 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/06 02:22:10 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_cycled_rotation(t_node **h, int t, int flag)
{
	if (t < node_len(h) / 2)
		while (--t >= 0)
			r(h, flag);
	else
	{
		t = node_len(h) - t;
		while (--t >= 0)
			rr(h, flag);
	}
}

int	node_find_index_fel(t_node **h, int (*f)(int, int))
{
	t_node	*fel;
	int		el;

	el = INT_MIN * !f(INT_MIN, INT_MAX) + INT_MAX * !f(INT_MAX, INT_MIN);
	fel = *h;
	while (fel)
	{
		if (f(fel->n, el))
			el = fel->i;
		fel = fel->next;
	}
	return (el);
}
