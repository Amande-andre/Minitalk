/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:18:45 by anmande           #+#    #+#             */
/*   Updated: 2023/02/12 15:12:12 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <../libft/libft.h>
# include <stdbool.h>

bool	g_char = false;

void	con_bit(int sig);
void	ft_sig(int sign, int nb);
void	ft_get_sign(void);
void	ft_sig_sem(int sign);

#endif