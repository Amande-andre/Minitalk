/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:22:39 by anmande           #+#    #+#             */
/*   Updated: 2023/02/11 21:07:09 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	while (str[i])
	{
		while (c < 8)
		{
			nb = (str[i] >> c++) & 1;
			usleep(100);
			ft_sig(pid, nb);
		}
		c = 0;
		i++;
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
