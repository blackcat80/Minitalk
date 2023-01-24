/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:38:52 by csitja-b          #+#    #+#             */
/*   Updated: 2023/01/22 15:51:13 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(void)
{
	ft_putstr("Comunication has failed!");
	exit(1);
}

void	confirm(int sig)
{
	static long long	count = -1;

	(void)sig;
	if (sig == SIGUSR1)
	{
		++count;
		usleep(10);
		ft_putstr(" -> Received bit [");
		ft_putnbr(count);
		write(1, "]\r", 2);
	}
	if (sig == SIGUSR2)
	{
		usleep(100);
		ft_putstr("Bites printed: ");
		ft_putnbr(count);
		ft_putchar('\n');
		exit(0);
	}
}

void	conv_bin(unsigned char s, int pid)
{
	int	base;

	base = 128;
	while (base > 0)
	{
		if (s >= base)
		{
			if (kill(pid, SIGUSR1) < 0)
				error();
			s = s - base;
			pause();
		}
		else
		{	
			if (kill(pid, SIGUSR2) < 0)
				error();
			pause();
		}
		base = base / 2;
		usleep(300);
	}	
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		return (-1);
	signal(SIGUSR1, &confirm);
	signal(SIGUSR2, &confirm);
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99999)
		exit(EXIT_FAILURE);
	while (argv[2][i])
	{
		conv_bin(argv[2][i], pid);
		i++;
	}
	conv_bin('\0', pid);
	while (1)
		pause();
	return (0);
}
