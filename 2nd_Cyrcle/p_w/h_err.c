/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_err.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:10:00 by tnakas            #+#    #+#             */
/*   Updated: 2024/06/07 16:41:43 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//is a valid digit
int	is_valid_digit(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '\0') || (s[i] < 32)
		|| ((s[i] == '-') && (s[i + 1] == '\0'))
		|| ((s[i] == '+') && (s[i + 1] == '\0')))
		return (0);
	if (s[++i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || '9' < s[i])
			return (0);
		i++;
	}
	return (1);
}

// is in the integers 
int	is_int(char *s)
{
	int				i;
	long long		n;
	int				sign;

	i = 0;
	n = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		n = (10 * n) + (s[i] - '0');
		i++;
	}
	n = sign * n;
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

// is a valid digit and integer
int	is_valid_and_int(char *s)
{
	if (!is_valid_digit(s) || !is_int(s))
		return (0);
	return (1);
}

//"565" "45" "" "45 34" "454", NULL
int	is_unique(int *ar, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (ar[i] == ar[j])
			{
				free(ar);
				return (0);
			}
		}
	}
	return (1);
}

long	ft_atol(char *s)
{
	long	n;
	int		i;
	int		sign;

	i = -1;
	n = 0;
	sign = 1;
	while (s[++i] && (s[i] == '\t'
			|| s[i] == ' ' || s[i] < 32))
		;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	i--;
	while (s[++i] && ('0' <= s[i] && s[i] <= '9'))
		n = (n * 10) + (s[i] - '0');
	return (sign * n);
}
