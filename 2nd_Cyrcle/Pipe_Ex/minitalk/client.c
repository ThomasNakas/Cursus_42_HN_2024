/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:07:38 by tnakas            #+#    #+#             */
/*   Updated: 2024/04/26 01:48:14 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int		*array_to_zero(int *array);
int		*update_the_array(int *array, const char c);
void	send_char(int number, int array[8]);

int	main(int argc, char **argv)
{
	int			*bit_array;
	int			num;
	int			j;

	if (argc != 3)
	{
		ft_printf("Must be two args int and string ");
		exit(1);
	}
	bit_array = (int *)malloc(sizeof(int) * 8);
	if (!bit_array)
		exit(0);
	bit_array = array_to_zero(bit_array);
	num = ft_atoi(argv[1]);
	j = -1;
	while (argv[2][++j])
	{
		bit_array = array_to_zero(bit_array);
		bit_array = update_the_array(bit_array, argv[2][j]);
		send_char(num, bit_array);
	}
	bit_array = array_to_zero(bit_array);
	send_char(num, bit_array);
	return (0);
}

int	*array_to_zero(int *array)
{
	int	counter;

	counter = -1;
	while (++counter <= 7)
		array[counter] = 0;
	return (array);
}

int	*update_the_array(int *array, const char c)
{
	int	piv;
	int	counter;

	piv = (int)c;
	counter = -1;
	while (++counter <= 7)
	{
		array[counter] = piv % 2;
		piv /= 2;
	}
	return (array);
}

void	send_char(int number, int array[8])
{
	int	counter;

	counter = -1;
	while (++counter <= 7)
	{
		if (array[counter] == 0)
		{
			kill(number, SIGUSR1);
			usleep(100);
		}
		else
		{
			kill(number, SIGUSR2);
			usleep(100);
		}
	}
}
