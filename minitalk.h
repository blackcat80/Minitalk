/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:41:55 by csitja-b          #+#    #+#             */
/*   Updated: 2023/01/21 17:49:24 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <sys/types.h>
# include <stdlib.h>

# define TRUE         (int)1
# define FALSE        (int)0

int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

#endif
