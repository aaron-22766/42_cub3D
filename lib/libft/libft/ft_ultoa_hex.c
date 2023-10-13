/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:52:49 by arabenst          #+#    #+#             */
/*   Updated: 2023/10/10 15:00:34 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_hex(unsigned long n, int lowercase, char *str, int i)
{
	const char	*base;

	if (lowercase)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < 16)
	{
		str[i] = base[n];
		return (i + 1);
	}
	i = ft_hex(n / 16, lowercase, str, i);
	i = ft_hex(n % 16, lowercase, str, i);
	return (i);
}

char	*ft_ultoa_hex(unsigned long n, int lowercase)
{
	unsigned long	lu;
	int				digits;
	char			*str;

	digits = 0;
	lu = n;
	while (lu)
	{
		lu /= 16;
		digits++;
	}
	if (!n)
		digits++;
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_hex(n, lowercase, str, 0);
	return (str);
}
