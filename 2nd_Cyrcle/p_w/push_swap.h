/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:05:34 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/09 12:19:34 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

//================STRUCTS========================
typedef struct s_node
{
	int						n;
	int						i;
	int						cost;
	int						target;
	int						t_index;
	int						dist;
	int						abs_dist;
	struct s_node			*next;
	struct s_node			*prev;
}	t_node;

typedef struct s_parsing
{
	int		i;
	int		*ar;
	t_node	*st;
	char	**res;
}	t_parsing;

typedef struct s_costs
{
	int	lena;
	int	lenb;
	int	maxa;
	int	maxb;
	int	ma;
	int	mb;
	int	ca;
	int	cb;
	int	i_c;
	int	t_i_c;
}	t_costs;

//===============HELPER_FOR_ERRORS================
int			is_valid_digit(char *s);
int			is_int(char *s);
int			is_valid_and_int(char *s);
int			is_unique(int *ar, int size);
long		ft_atol(char *s);
//=============MATH_FUNCTIONS=====================
int			m_abs(int a, int b);
int			m_psqrt(int a);
int			m_kvar(int a);
//=============NODE_OPERATIONS_ONE================
t_node		*node_create(int n);
t_node		*node_add_end(t_node *list, t_node *new);
t_node		*node_add_begin(t_node *list, t_node *new);
void		node_print(t_node **h);
void		node_print_simple(t_node **h);
//=============NODE_OPERATIONS_TWO================
int			node_min(t_node **h);
int			node_max(t_node **h);
int			node_is_sorted(t_node **h);
int			node_len(t_node **h);
void		node_free(t_node **h);
//============NODE_OPERATIONS_THREE===============
t_node		*node_find_last(t_node **h);
t_node		*node_find(t_node **h, int n);
void		node_update_index(t_node **h);
void		node_update_cost_many(t_node **hb, t_node **ha);
//============NODE_OPERATIONS_FOUR================
int			array_compute_min(int *ar, int sz);
int			array_find_min(int *ar, int sz, int min);
void		node_min_target(t_node **mntr, t_node **h, int index);
void		node_update_target_one(t_node **mntr, t_node **st_a);
void		node_update_target_many(t_node **hb, t_node**ha);
//============NODE_OPERATIONS_FIVE================
t_node		*node_last(t_node **h);
t_node		*node_f_minr(t_node **h, int range);
t_node		*node_f_maxr(t_node **h, int range);
void		node_update_many(t_node **h1, t_node **h2);
int			node_find_hdist(t_node **h, int nb);
//============HELPER_FOR_PARSING==================
void		exit_message(void);
void		is_valid_and_int_argv(int argc, char **argv);
t_node		*array_to_list(t_node *list, int *ar, int size);
t_node		*parsing(int *argc, char ***argv);
//============HELPER_SPECIAL_SPLIT================
int			words(const char *s, char c);
int			word_len(const char *s, int start, char c);
void		ft_free(char **s, int last);
void		ft_free_push_swap(char **s, int last, int words);
char		**split_improved(const char *s, char c);
//============UNCOMPLICATED_SORTING_OPERATIONS====
void		array_bubble_sorting(int *a, int sz);
void		array_indexing(int *a, int *b, int sz);
int			*array_dup(int *src, int sz);
void		array_print(int	*a, int sz);
void		array_comb(int	*a, int sz);
//==========SORTING_BY_PUSH_SWAP==================
void		sort_three(t_node **h);
void		node_sort_mini_turk(t_node **h1, t_node **h2, int r);
//============UNCOMPLICATED_COMANDS_ONE===============
void		p(t_node **h1, t_node **h2, int f);
void		s(t_node **h, int f);
void		r(t_node **h, int f);
void		rr(t_node **h, int f);
void		r_without_flag(t_node **h);
//============UNCOMPLICATED_COMMANDS_TWO===============
int			ascending(int a, int b);
int			descending(int a, int b);
int			m_r_stp(int a, int b);
void		m_r_strt_end(t_node **h, int (*f)( int, int),
				t_node	**st, t_node	**end);
int			node_cycled_sorted(t_node **h, int (*f)( int, int));
//============UNCOMPLICATED_COMMANDS_THREE===============
void		node_cycled_rotation(t_node **h, int r, int flag);
int			node_find_index_fel(t_node **h, int (*f)(int, int));
//============ALGORYTHMIC_PATTERNS========================
// void		node_kpush_flag(t_node **h1, t_node **h2, t_node **temp, int *f);
void		node_kpush_a_to_b(t_node **h1, t_node **h2);
void		node_kpush_b_to_a(t_node **h1, t_node **h2);
//============MEMORY_RELATED_FUNCTIONS=====================
int			push_swap_main_helper(t_node **sta, t_node **stb,
				int argc);
#endif
