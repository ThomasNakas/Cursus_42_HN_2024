/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_par.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:26:32 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/09 10:59:53 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_message(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	is_valid_and_int_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!is_valid_and_int(argv[i]) || argc == 1)
			exit_message();
	}
}

t_node	*array_to_list(t_node *list, int *ar, int size)
{
	int		i;
	t_node	*temp;

	i = -1;
	while (++i < size)
	{
		temp = node_create(ar[i]);
		if (!temp)
			return (NULL);
		list = node_add_end(list, temp);
	}
	node_update_index(&list);
	free(ar);
	return (list);
}

t_node	*parsing(int *argc, char ***argv)
{
	t_parsing	p;

	p.st = NULL;
	p.res = NULL;
	if (*argc == 2)
	{
		p.res = split_improved((*argv)[1], ' ');
		if (!p.res)
			return (NULL);
		*argc = words((*argv)[1], ' ') + 1;
		*argv = p.res;
	}
	is_valid_and_int_argv(*argc, *argv);
	p.ar = (int *)malloc(sizeof(int) * ((*argc) - 1));
	if (!p.ar)
		return (NULL);
	p.i = 0;
	while (++p.i < (*argc))
		p.ar[p.i - 1] = (int)ft_atol((*argv)[p.i]);
	array_comb(p.ar, (*argc) - 1);
	if (!is_unique(p.ar, (*argc) - 1))
		exit_message();
	return (array_to_list(p.st, p.ar, (*argc) - 1));
}
