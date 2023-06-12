/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:14:23 by hatesfam          #+#    #+#             */
/*   Updated: 2023/06/10 18:53:14 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// static void	action(int sig)
// {
// 	static int	received = 0;

// 	if (sig == SIGUSR1)
// 		++received;
// 	else
// 	{
// 		ft_putnbr_fd(received, 1);
// 		ft_putchar_fd('\n', 1);
// 		exit(0);
// 	}
// }

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	// ft_putstr_fd("Sent    : ", 1);
	// ft_putnbr_fd(ft_strlen(argv[2]), 1);
	// ft_putchar_fd('\n', 1);
	// ft_putstr_fd("Received: ", 1);
	// signal(SIGUSR1, action);
	// signal(SIGUSR2, action);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	// while (1)
	// 	pause();
	// return (0);
}
