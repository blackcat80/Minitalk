/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:29:43 by csitja-b          #+#    #+#             */
/*   Updated: 2023/01/21 18:10:39 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	conv_bin(char *s, int pid)
{
	unsigned int		i;
	unsigned int		base;
	unsigned char		letra;

	i = 0;
	while (s[i])
	{
		base = 128;
		letra = s[i];
		while (base > 0)
		{
			if (letra >= base)
			{
				kill(pid, SIGUSR1);
				letra = letra - base;
			}
			else
				kill(pid, SIGUSR2);
			base = base / 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99999)
		exit(EXIT_FAILURE);
	conv_bin(argv[2], pid);
	while (42)
		pause();
	return (0);
}
