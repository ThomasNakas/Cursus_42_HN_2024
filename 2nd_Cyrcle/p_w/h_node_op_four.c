/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_node_op_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:58:09 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/05 22:49:51 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_compute_min(int *ar, int sz)
{
	int			min;
	int			i;

	min = INT_MAX;
	i = -1;
	while (++i < sz)
		if (ar[i] < min)
			min = ar[i];
	return (min);
}

int	array_find_min(int *ar, int sz, int min)
{
	int	i;

	i = -1;
	while (++i < sz)
		if (ar[i] == min)
			return (i);
	return (0);
}

void	node_min_target(t_node **mntr, t_node **h, int index)
{
	int		i;
	t_node	*temp;

	i = -1;
	temp = *h;
	while (++i < index)
		temp = temp->next;
	(*mntr)->target = temp->n;
}

void	node_update_target_one(t_node **mntr, t_node **stack_a)
{
	int			len;
	int			*ar;
	int			i;
	t_node		*temp;

	len = node_len(stack_a);
	ar = (int *)malloc(sizeof(int) * (len));
	i = 0;
	temp = *stack_a;
	if (!ar)
		return ;
	while (temp)
	{
		ar[i] = (temp->n) - ((*mntr)->n);
		ar[i] = ar[i] * ((ar[i] < 0) * (-1) + (ar[i] >= 0));
		i++;
		temp = temp->next;
	}
	(*mntr)->abs_dist = array_compute_min(ar, len);
	(*mntr)->t_index = array_find_min(ar, len, (*mntr)->abs_dist);
	node_min_target(mntr, stack_a, (*mntr)->t_index);
	(*mntr)->dist = ((*mntr)->target) - ((*mntr)->n);
	free(ar);
}

void	node_update_target_many(t_node **hb, t_node**ha)
{
	t_node	*tempb;

	tempb = *hb;
	while (tempb)
	{
		node_update_target_one(&tempb, ha);
		tempb = tempb->next;
	}
}
