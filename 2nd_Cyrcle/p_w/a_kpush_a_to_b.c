/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_kpush_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:58:51 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/08 09:03:34 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_temp_next(t_node **temp)
{
	if ((*temp)->next)
		*temp = (*temp)->next;
}

void	node_ktemp_next(t_node **h1, t_node **temp, int kvar)
{
	if ((*temp)->next && (*temp)->next->n <= kvar && (*temp)->n <= kvar + 1)
	{
		node_temp_next(temp);
		s(h1, 0);
	}
	else
	{
		node_temp_next(temp);
		r(h1, 0);
	}
}

void	node_kpush_icond(t_node **h1, t_node **h2, t_node **temp, int kvar)
{
	int	i;

	i = 0;
	while ((*h1))
	{
		if ((*temp)->n <= i)
		{
			i++;
			node_temp_next(temp);
			p(h1, h2, 1);
			r(h2, 1);
		}
		else if ((*temp)->n <= i + kvar)
		{
			i++;
			node_temp_next(temp);
			p(h1, h2, 1);
		}
		else
		{
			node_temp_next(temp);
			r(h1, 0);
		}
	}
}

void	node_kpush_a_to_b(t_node **h1, t_node **h2)
{
	int		kvar;
	t_node	*temp;

	kvar = m_kvar(node_len(h1));
	temp = (*h1);
	node_kpush_icond(h1, h2, &temp, kvar);
}

void	node_kpush_b_to_a(t_node **h1, t_node **h2)
{
	t_node	*first;
	int		hdst;

	first = (*h2);
	hdst = 0;
	while (first)
	{
		node_update_many(h1, h2);
		hdst = node_find_hdist(h2, node_find(h2, node_max(h2))->n);
		node_cycled_rotation(h2, hdst, 1);
		first = (*h2);
		first = first->next;
		p(h2, h1, 0);
	}
}
