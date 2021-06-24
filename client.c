/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:00:25 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/24 18:03:06 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, char *message)
{
	int	bit;
	int	len;

	bit = 64;
	len = ft_strlen(message);
	while (len >= 0)
	{
		if (*message & bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit >>= 1;
		if (bit == 0)
		{
			len--;
			message++;
			bit = 64;
		}
		usleep(200);
	}
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("./client [server_pid] [\"message\"]\n", 1);
		return (0);
	}
	send_sig(ft_atoi(argv[1]), argv[2]);
	return (0);
}
