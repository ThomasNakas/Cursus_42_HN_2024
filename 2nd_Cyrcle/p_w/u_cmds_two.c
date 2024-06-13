/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_cmds_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:37:40 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/05 20:06:07 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending(int a, int b)
{
	return (a < b);
}

int	descending(int a, int b)
{
	return (a > b);
}

int	m_r_stp(int a, int b)
{
	return ((a - b < 0) + (-1) * (a - b >= 0));
}

void	m_r_strt_end(t_node **h, int (*f)( int, int),
		t_node	**st, t_node	**end)
{
	*st = node_find(h, node_min(h) * (*f)(node_min(h), node_max(h))
			+ node_max(h) * (*f)(node_max(h), node_min(h)));
	*end = node_find(h, node_min(h) * (!(*f)(node_min(h), node_max(h)))
			+ node_max(h) * (!(*f)(node_max(h), node_min(h))));
}

int	node_cycled_sorted(t_node **h, int (*f)( int, int))
{
	t_node	*end;
	t_node	*start;
	t_node	*temp;
	int		i;

	if (!(*h))
		return (-1);
	node_update_index(h);
	if (!((*h)->next))
		return ((*h)->i);
	m_r_strt_end(h, f, &start, &end);
	temp = start;
	i = 0;
	while (temp->n == (start->n + m_r_stp(start->n, end->n) * i)
		&& (i < m_abs(start->n, end->n)))
	{
		i++;
		if (temp->next == NULL)
			temp = *h;
		else
			temp = temp->next;
	}
	if (i == m_abs(start->n, end->n))
		return (start->i);
	return (-1);
}
