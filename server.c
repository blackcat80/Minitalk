/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:32:16 by csitja-b          #+#    #+#             */
/*   Updated: 2023/01/21 17:53:44 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	conv_txt(char *s)
{
	int		i;
	int		base;
	char	bit;
	int		control;
	int		result;

	i = 7;
	while (s[i])
	{
		base = 1;
		control = i;
		result = 0;
		while (base <= 128)
		{
			bit = s[control];
			if (bit == '1')
				result = result + base;
			base = base * 2;
			control--;
		}
		write(1, &result, 1);
		i = i + 8;
	}
}

void	alm_bin(int sig)
{
	static int	i = 0;
	static char	c[8];

	if (sig == SIGUSR1)
		c[i] = '1';
	else if (sig == SIGUSR2)
		c[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		conv_txt(c);
	}
}

int	main(void)
{
	ft_putstr("Hello I'm MiniTalk!\n");
	ft_putstr("My Server PID is:");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (TRUE)
	{
		signal(SIGUSR2, alm_bin);
		signal(SIGUSR1, alm_bin);
		pause();
	}
	return (0);
}
