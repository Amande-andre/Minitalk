/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:17:53 by anmande           #+#    #+#             */
/*   Updated: 2023/02/12 15:15:06 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	con_bit(int sig)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static int				j = 0;
	char	*str;

	str = malloc(65000);
	c |= (sig << i++);
	if (i > 7)
	{
		if (c == '\0')
		{
			ft_putchar_fd(c, 1);
			ft_putchar_fd('\n', 1);
		}
		else
		{
			str[j] = c;
			// g_char = true;
		}
		if (i == 6)
			g_char = true;
		i = 0;
		c = 0;
	}
}

void	ft_sig_sem(int sign)
{
	if (sign == SIGUSR1)
		con_bit(0);
	else if (sign == SIGUSR2)
		con_bit(1);
}

int	main(void)
{
	int		pid;
	char	*str;

	pid = getpid();
	str = ft_itoa(pid);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	free(str);
		if (!str)
			return (0);
	if (signal(SIGUSR1, ft_sig_sem) == SIG_ERR)
		write(1, "SIGUSR1 ERROR\n", 15);
	if (signal(SIGUSR2, ft_sig_sem) == SIG_ERR)
		write(1, "SIGUSR2 ERROR\n", 15);
	while (1)
	{
	}
	return (0);
}
