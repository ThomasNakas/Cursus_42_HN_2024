/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_five.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:31:57 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/05 02:28:13 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_sort_mini_turk(t_node **h1, t_node **h2, int r)
{
	int	i;

	i = -1;
	node_cycled_rotation(h1, node_cycled_sorted(h1, ascending), 0);
	if (node_is_sorted(h1))
		return ;
	while (r-- > 3)
	{
		node_update_index(h1);
		node_cycled_rotation(h1, node_find(h1, ++i)->i, 0);
		p(h1, h2, 1);
	}
	sort_three(h1);
	while (i-- >= 0)
		p(h2, h1, 0);
	return ;
}
