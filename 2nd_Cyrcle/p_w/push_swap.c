/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:05:01 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/09 12:23:26 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_stack_helper(t_node ***sta, int argc)
{
	if (argc == 1 || argc == 2)
		exit (0);
	else if (argc - 1 == 2)
	{
		if ((**sta)->n > (**sta)->next->n)
			s(*sta, 0);
		node_free(*sta);
		exit(0);
	}
}

void	simple_stack_returns(t_node **sta, t_node **stb, int argc)
{
	simple_stack_helper(&sta, argc);
	if (node_is_sorted(sta))
	{
		node_free(sta);
		exit(0);
	}
	else if (argc - 1 == 3)
	{
		sort_three(sta);
		node_free(sta);
		exit(0);
	}
	else if (argc - 1 <= 6)
	{
		node_sort_mini_turk(sta, stb, argc - 1);
		node_free(sta);
		exit (0);
	}
}

void	check_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_node	*sta;
	t_node	*stb;

	sta = parsing(&argc, &argv);
	if (!sta)
		return (free(sta), 0);
	stb = NULL;
	simple_stack_returns(&sta, &stb, argc);
	if (!node_is_sorted(&sta))
	{
		node_kpush_a_to_b(&sta, &stb);
		node_kpush_b_to_a(&sta, &stb);
	}
	node_free(&sta);
	return (0);
}
