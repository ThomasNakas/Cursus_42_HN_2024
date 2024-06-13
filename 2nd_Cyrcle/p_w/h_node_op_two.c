/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_node_op_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:23:13 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/06 17:58:14 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_min(t_node **h)
{
	t_node	*temp;
	int		min;

	min = INT_MAX;
	temp = (*h);
	while (temp)
	{
		if (temp->n < min)
			min = temp->n;
		temp = temp->next;
	}
	return (min);
}

int	node_max(t_node **h)
{
	t_node	*temp;
	int		max;

	max = INT_MIN;
	temp = (*h);
	while (temp)
	{
		if (temp->n > max)
			max = temp->n;
		temp = temp->next;
	}
	return (max);
}

int	node_is_sorted(t_node **h)
{
	t_node	*temp;

	temp = *h;
	while (temp && temp->next)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	node_len(t_node **h)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *h;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	node_free(t_node **h)
{
	t_node	*last;
	t_node	*temp;

	last = *h;
	while (last->next)
		last = last->next;
	temp = last;
	while (temp->prev)
	{
		temp = temp->prev;
		free(last);
		last = temp;
	}
	free(temp);
}
