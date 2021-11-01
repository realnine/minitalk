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
	static char	c = 0; // 클라이언트로 부터 전달 받을 한 문자의 아스키 코드 값
	static int	bit = 64;

	if (num == SIGUSR2) // 해당 위치의 비트값이 1일 때,
		c += bit; 
	bit >>= 1;
	if (bit == 0) // 한 문자의 모든 비트값을 확인했으면 출력
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
	signal(SIGUSR1, sighandler); // 실행이 아니라 설정해놓는 것
		// 현재 프로세스에 SIGUSR1 시그널이 발생하면 sighandler()함수 실행
		// SIGUSR1값이 sighandler()함수의 인수로 들어감
	signal(SIGUSR2, sighandler);
	ft_putstr_fd("pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
