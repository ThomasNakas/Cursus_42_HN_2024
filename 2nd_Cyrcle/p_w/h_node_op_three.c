/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_node_op_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:23:13 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/06 18:06:52 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_find_last(t_node **h)
{
	t_node	*temp;

	temp = *h;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_node	*node_find(t_node **h, int n)
{
	t_node	*temp;

	temp = *h;
	while (temp)
	{
		if (temp->n == n)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	node_update_index(t_node **h)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *h;
	if (!temp)
		return ;
	while (temp)
	{
		temp->i = i;
		i++;
		temp = temp->next;
	}
}

void	node_update_cost_many(t_node **hb, t_node **ha)
{
	t_costs	c;
	t_node	*temp;

	temp = *hb;
	if (!temp)
		return ;
	c.lena = node_len(ha);
	c.lenb = node_len(hb);
	c.maxa = node_max(ha);
	c.maxb = node_max(hb);
	c.ma = c.lena / 2;
	c.mb = c.lenb / 2;
	c.i_c = (temp->i) * (temp->i < c.mb)
		+ (c.maxb - temp->i + 1) * (temp->i >= c.mb);
	c.t_i_c = (temp->t_index) * (temp->t_index < c.ma)
		+ (c.maxb - temp->t_index + 1) * (temp->t_index >= c.ma);
	while (temp)
	{
		temp->cost = c.i_c + c.t_i_c + (temp->abs_dist - 1) + 1;
		temp = temp->next;
	}
}
