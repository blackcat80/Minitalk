/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:19:09 by csitja-b          #+#    #+#             */
/*   Updated: 2023/01/22 15:49:30 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *data)
{
	static int	bite;
	static char	ch;

	(void) data;
	usleep(100);
	if (sig == SIGUSR1)
		ch = ch | 1 << (7 - bite);
	bite++;
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_putstr("sending failed");
	if (bite == 8)
	{
		write(1, &ch, 1);
		if (ch == '\0')
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_putstr("sending failed");
		bite = 0;
		ch = '\0';
	}
}

static void	ft_get_pid(void)
{
	int	pid;

	pid = getpid();
	if (!pid)
		ft_putstr("No PID generated");
	ft_putnbr(pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_get_pid();
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		pause();
	}
	return (0);
}
