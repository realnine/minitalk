/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:03:24 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/24 18:11:21 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int num)
{
	static char	c = 0;
	static int	bit = 64;

	if (num == SIGUSR2)
		c += bit;
	bit >>= 1;
	if (bit == 0)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		c = 0;
		bit = 64;
	}
	return ;
}

int		main(void)
{
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	ft_putstr_fd("pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
