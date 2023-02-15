/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:22:39 by anmande           #+#    #+#             */
/*   Updated: 2023/02/15 15:47:45 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_sig(int pid, int nb)
{
	if (nb == 0)
		if (kill(pid, SIGUSR1) == -1)
			write(1, "ERROR SIGUSR1\n", 15);
	if (nb == 1)
		if (kill(pid, SIGUSR2) == -1)
			write(1, "ERROR SIGUSR2\n", 15);
}

void	ft_bin(int pid, char *str)
{
	char	c;
	int		nb;
	int		i;

	c = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (c < 8)
		{
			nb = (str[i] >> c++) & 1;
			ft_sig(pid, nb);
			usleep(300);
		}
		c = 0;
		i++;
	}
	while (c < 8)
	{
		nb = (str[i] >> c++) & 1;
		ft_sig(pid, nb);
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid <= 1)
		return (0);
	ft_bin(pid, av[2]);
	return (ac);
}
