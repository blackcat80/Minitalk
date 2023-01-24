/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:30:18 by csitja-b          #+#    #+#             */
/*   Updated: 2023/01/21 18:16:42 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	unsigned int	result;
	unsigned int	i;

	i = 0;
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	number;

	number = n;
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number %= 10;
	}
	ft_putchar(number + '0');
	return ;
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) != 6)
			return ;
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
