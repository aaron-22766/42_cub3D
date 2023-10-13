/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:38:56 by arabenst          #+#    #+#             */
/*   Updated: 2023/10/10 14:56:25 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static ssize_t	ft_putnbr_fd_helper(int n, int fd, int count)
{
	if (n < 10)
	{
		if (ft_putchar_fd('0' + n, fd) == -1)
			return (-1);
		count++;
	}
	else
	{
		count = ft_putnbr_fd_helper(n / 10, fd, count);
		count = ft_putnbr_fd_helper(n % 10, fd, count);
	}
	return (count);
}

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	count;

	count = 0;
	if (n == -2147483648)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		if (ft_putchar_fd('2', fd) == -1)
			return (-1);
		count += 2;
		n = 147483648;
	}
	else if (n < 0)
	{
		n = -n;
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		count++;
	}
	return (ft_putnbr_fd_helper(n, fd, count));
}
