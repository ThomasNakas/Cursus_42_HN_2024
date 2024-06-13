/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_cmds_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:37:40 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/06 12:16:00 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_node **h, int f)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!(*h) || !((*h)->next))
		return ;
	first = *h;
	second = first->next;
	third = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*h = second;
	if (f == 0)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

// I 'm saving only the pushed elements
// first->next, first->prev, first->next,->prev *h1
// *h2->previous, *h2
void	p(t_node **h1, t_node **h2, int f)
{
	t_node	*first;
	t_node	*second;

	if (!h1 || !*h1)
		return ;
	first = *h1;
	second = first->next;
	if (second)
		second->prev = NULL;
	*h1 = second;
	first->next = *h2;
	if (*h2)
		(*h2)->prev = first;
	first->prev = NULL;
	*h2 = first;
	if (f == 0)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	r(t_node **h, int f)
{
	t_node	*first;
	t_node	*temp;

	if (!(*h) || !((*h)->next))
		return ;
	first = *h;
	temp = *h;
	while (temp->next)
		temp = temp->next;
	first->next->prev = NULL;
	temp->next = first;
	first->prev = temp;
	*h = first->next;
	first->next = NULL;
	if (f == 0)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **h, int f)
{
	t_node	*last;
	t_node	*s_last;

	if (!h || !(*h) || !(*h)->next)
		return ;
	last = *h;
	while (last->next)
		last = last->next;
	s_last = last->prev;
	if (s_last)
		s_last->next = NULL;
	last->next = (*h);
	(*h)->prev = last;
	(*h) = last;
	last->prev = NULL;
	if (f == 0)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	r_without_flag(t_node **h)
{
	t_node	*first;
	t_node	*temp;

	if (!(*h) || !((*h)->next))
		return ;
	first = *h;
	temp = *h;
	while (temp->next)
		temp = temp->next;
	first->next->prev = NULL;
	temp->next = first;
	first->prev = temp;
	*h = first->next;
	first->next = NULL;
}

// void	s(t_node **h, int f)
// {
// 	t_node	*first;
// 	t_node	*second;
// 	t_node	*third;

// 	if (!(*h) || !((*h)->next))
// 		return ;
// 	first = *h;
// 	second = first->next;
// 	third = second->next;
// 	second->next = first;
// 	second->prev = NULL;
// 	first->prev = second;
// 	first->next = third;
// 	if (third)
// 		third->prev = first;
// 	*h = second;
// 	if (f == 0)
// 		ft_putstr_fd("=======a=======\n", 1);
// 	if (f == 1)
// 		ft_putstr_fd("=======b=======\n", 1);
// 	node_print_simple(h);
// }

// // I 'm saving only the pushed elements
// // first->next, first->prev, first->next,->prev *h1
// // *h2->previous, *h2
// void	p(t_node **h1, t_node **h2, int f)
// {
// 	t_node	*first;
// 	t_node	*second;

// 	if (!h1 || !*h1)
// 		return ;
// 	first = *h1;
// 	second = first->next;
// 	if (second)
// 		second->prev = NULL;
// 	*h1 = second;
// 	first->next = *h2;
// 	if (*h2)
// 		(*h2)->prev = first;
// 	first->prev = NULL;
// 	*h2 = first;
// 	if (f == 0)
// 		ft_putstr_fd("=======a=======\n", 1);
// 	node_print_simple(h1);
// 	if (f == 1)
// 		ft_putstr_fd("=======b=======\n", 1);
// 	node_print_simple(h2);
// }

// void	r(t_node **h, int f)
// {
// 	t_node	*first;
// 	t_node	*temp;

// 	if (!(*h) || !((*h)->next))
// 		return ;
// 	first = *h;
// 	temp = *h;
// 	while (temp->next)
// 		temp = temp->next;
// 	first->next->prev = NULL;
// 	temp->next = first;
// 	first->prev = temp;
// 	*h = first->next;
// 	first->next = NULL;
// 	if (f == 0)
// 		ft_putstr_fd("=======a=======\n", 1);
// 	if (f == 1)
// 		ft_putstr_fd("=======b=======\n", 1);
// 	node_print_simple(h);
// }

// void	rr(t_node **h, int f)
// {
// 	t_node	*last;
// 	t_node	*s_last;

// 	if (!h || !(*h) || !(*h)->next)
// 		return ;
// 	last = *h;
// 	while (last->next)
// 		last = last->next;
// 	s_last = last->prev;
// 	if (s_last)
// 		s_last->next = NULL;
// 	last->next = (*h);
// 	(*h)->prev = last;
// 	(*h) = last;
// 	last->prev = NULL;
// 	if (f == 0)
// 		ft_putstr_fd("=======a=======\n", 1);
// 	if (f == 1)
// 		ft_putstr_fd("=======b=======\n", 1);
// 	node_print_simple(h);
// }