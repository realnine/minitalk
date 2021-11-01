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
		// bit 값의 변화 64 => 32 => 16 => 8 => 4 => 2 => 1 => 0 ( >> 연산의 결과)
		// 64 = 100 0000 (아스키코드는 7bit로 표현가능)
		// 32 = 010 0000
	len = ft_strlen(message);
	while (len >= 0) // message길이 x 7(bit값 변화 횟수) 만큼 반복
	{
		//만약 *message 가 'a'이면 아스키코드 97(110 0001)
		if (*message & bit) // *message(문자 하나)와 bit를 and 연산
			kill(pid, SIGUSR2); 
		else
			kill(pid, SIGUSR1);
		// bit가 100 0000(64) 일때, 'a'(110 0001)와 연산결과 => 100 0000 이기 때문에
		// if ()문은 true
		// bit가 010 0000(32) 일때, 'a'(110 0001)와 연산결과 => 010 0000 이기 때문에
		// if ()문은 true
		// bit가 001 0000(16) 일때, 'a'(110 0001)와 연산결과 => 000 0000 이기 때문에
		// if ()문은 false

		bit >>= 1;
		if (bit == 0) // 문자하나의 정보를 다 보냈으면 다음 문자
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
