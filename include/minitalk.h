/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:18:45 by anmande           #+#    #+#             */
/*   Updated: 2023/02/12 14:56:11 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <../libft/libft.h>
# include <stdbool.h>

bool	g_char = false;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

void	con_bit(int sig, char *str);
void	ft_sig(int sign, int nb);
void	ft_get_sign(void);
void	ft_sig_sem(int sign, char *str);

#endif