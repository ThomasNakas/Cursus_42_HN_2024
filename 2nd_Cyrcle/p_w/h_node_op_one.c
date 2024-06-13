/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_node_op_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:02:27 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/05 03:56:56 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_print_simple(t_node **h)
{
	t_node	*temp;

	temp = *h;
	while (temp)
	{
		ft_printf("[ %d ] <-> ", temp->n);
		temp = temp->next;
	}
	ft_printf(" NULL\n");
}

void	node_print(t_node **h)
{
	t_node	*temp;

	temp = *h;
	while (temp)
	{
		ft_printf("[i = %d | cost = %d", temp->i, temp->cost);
		ft_printf(" target = %d | t_index = %d", temp->target, temp->t_index);
		ft_printf(" abs_dist = %d | dist = %d", temp->abs_dist, temp->dist);
		ft_printf(" | value = %d]\n", temp->n);
		ft_printf("                            <||>\n");
		temp = temp->next;
	}
	ft_printf("NULL\n");
}

t_node	*node_create(int n)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->n = n;
	new->i = 0;
	new->cost = 0;
	new->target = 0;
	new->dist = 0;
	new->abs_dist = 0;
	new->t_index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*node_add_end(t_node *list, t_node *new)
{
	t_node	*temp;

	temp = list;
	if (!list)
		return (new);
	while (temp->next)
		temp = temp->next;
	new->prev = temp;
	temp->next = new;
	new->next = NULL;
	return (list);
}

t_node	*node_add_begin(t_node *list, t_node *new)
{
	if (!list)
		return (new);
	list->prev = new;
	new->next = list;
	new->prev = NULL;
	return (new);
}
