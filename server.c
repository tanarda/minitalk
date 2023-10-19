/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:32:59 by mehtan            #+#    #+#             */
/*   Updated: 2022/12/15 17:33:02 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	int			x;
	static int	bit = 7;
	static int	set = 0;

	x = 0;
	if (sig == SIGUSR1)
		x = 1;
	else if (sig == SIGUSR2)
		x = 0;
	set += x << bit;
	if (bit == 0)
	{
		ft_printf("%c", set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

int	main(int argc, char **argv)
{
	int					pid;

	pid = getpid();
	ft_printf("PİD: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
