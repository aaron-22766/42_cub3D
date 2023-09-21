/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:14:40 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/24 04:03:50 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n / base > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_converter(unsigned long n, int base, int reg, t_flags *flags)
{
	char			*num;
	int				len;
	int				digit;

	if (flags->is_acc && flags->acc == 0 && n == 0)
		return (ft_strdup(""));
	len = ft_numlen(n, base);
	num = ft_calloc(len + 1, 1);
	reg = 97 - reg * 32;
	while (len--)
	{
		digit = n % base;
		if (digit > 9)
			num[len] = reg + digit - 10;
		else
			num[len] = digit + '0';
		n /= base;
	}
	return (num);
}
