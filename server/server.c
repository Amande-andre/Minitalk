/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:17:53 by anmande           #+#    #+#             */
/*   Updated: 2023/02/15 15:45:02 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	con_bit(int sig)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static int				j = 0;
	static char	str[600000];

	//*str = NULL;
	c |= (sig << i++);
	if (i > 7)
	{
		if (c == '\0')
		{
			//ft_putchar_fd('c', 1);
			str[j] = '\0';
			ft_putstr_fd(str, 1);
			ft_putchar_fd('\n', 1);
			j = 0;
		}
		else
		{
			//ft_putchar_fd(c, 1);
			str[j] = c;
			j++;
		}
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
