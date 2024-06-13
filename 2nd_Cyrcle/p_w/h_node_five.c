/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_node_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:40:08 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/06 16:12:01 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_last(t_node **h)
{
	t_node	*last;

	last = (*h);
	while (last->next)
		last = last->next;
	return (last);
}

t_node	*node_f_minr(t_node **h, int range)
{
	t_node	*minr;
	t_node	*temp;
	int		m;
	int		i;

	i = -1;
	m = INT_MAX;
	temp = *h;
	minr = NULL;
	while (temp && ++i < range)
	{
		if (temp->n < m)
			minr = temp;
		temp = temp -> next;
	}
	return (minr);
}

t_node	*node_f_maxr(t_node **h, int range)
{
	t_node	*maxr;
	t_node	*temp;
	int		m;
	int		i;

	i = -1;
	m = INT_MIN;
	temp = *h;
	maxr = NULL;
	while (temp && ++i < range)
	{
		if (temp->n > m)
			maxr = temp;
		temp = temp -> next;
	}
	return (maxr);
}

void	node_update_many(t_node **h1, t_node **h2)
{
	node_update_index(h2);
	node_update_index(h1);
}

int	node_find_hdist(t_node **h, int nb)
{
	t_node	*temp;
	int		i;

	temp = *h;
	i = 0;
	while (temp->next && temp->n != nb)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
