/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:07:44 by tnakas            #+#    #+#             */
/*   Updated: 2024/04/26 18:00:43 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int			pow_two(int base, int exp);
void		sig_handler(int signum);
// char		*mes_to_zero(char *mes);

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_printf("\033[1;36m");
	ft_printf("        .__       .__  __         .__   __    \n");
	ft_printf("  _____ |__| ____ |__|/  |______  |  | |  | __\n");
	ft_printf(" /     \\|  |/    \\|  \\   __\\__  \\ |  | |  |/ /\n");
	ft_printf("|  Y Y  \\  |   |  \\  ||  |  / __ \\|  |_|    < \n");
	ft_printf("|__|_|  /__|___|  /__||__| (____  /____/__|_ \\\n");
	ft_printf("      \\/        \\/              \\/          \\/\n");
	ft_printf("\033[0m");
	printf("Server is running in the pid: %d . . .\n", getpid());
	while (1)
		pause();
	return (0);
}

int	pow_two(int base, int exp)
{
	int	i;
	int	res;

	res = 1;
	if (exp == 0)
		return (1);
	i = -1;
	while (++i < exp)
		res *= base;
	return (res);
}

void	sig_handler(int signum)
{
	char		temp;
	static int	g_shr;
	static int	g_i;

	if (signum == SIGUSR2)
		g_shr += 1 * pow_two(2, g_i);
	g_i++;
	if (g_i == 8)
	{
		temp = (char) g_shr;
		if (temp == '\0')
			write(1, "\n", 1);
		write(1, &temp, 1);
		g_i = 0;
		g_shr = 0;
	}
}
// void	sig_handler(int signum)
// {
// 	char		temp;
// 	static int	g_shr;
// 	static int	g_i;
// 	static int	g_j;
// 	static char	mes[10240];

// 	if (signum == SIGUSR2)
// 		g_shr += 1 * pow_two(2, g_i);
// 	g_i++;
// 	if (g_i == 8)
// 	{
// 		temp = (char) g_shr;
// 		mes[g_j] = temp;
// 		g_j++;
// 		if (temp == '\0')
// 		{
// 			ft_printf("%s\n", mes);
// 			mes_to_zero(&*mes);
// 			g_j = 0;
// 		}
// 		g_i = 0;
// 		g_shr = 0;
// 	}
// }

// char	*mes_to_zero(char *mes)
// {
// 	int	counter;

// 	counter = -1;
// 	while (++counter < ft_strlen(mes))
// 		mes[counter] = (char)0;
// 	return (mes);
// }
