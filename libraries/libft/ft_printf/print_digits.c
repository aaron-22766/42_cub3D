/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:17:02 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/24 04:04:20 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list args, t_flags *flags)
{
	flags->str = ft_converter((unsigned long) va_arg(args, unsigned int *),
			16, 0, flags);
	if (!flags->str)
		return (-1);
	flags->prefix = "0x";
	flags->p_len = 2;
	set_order(flags, ft_strlen(flags->str));
	return (1);
}

int	print_hex(va_list args, t_flags *flags, int reg)
{
	unsigned int	hex;

	hex = va_arg(args, unsigned int);
	flags->str = ft_converter(hex, 16, reg, flags);
	if (!(flags->str))
		return (-1);
	if (flags->tag && reg == 1 && hex)
		flags->prefix = "0X";
	else if (flags->tag && reg == 0 && hex)
		flags->prefix = "0x";
	if (flags->tag && hex)
		flags->p_len = 2;
	set_order(flags, ft_strlen(flags->str));
	return (1);
}

int	print_int(va_list args, t_flags *flags)
{
	long int		n;

	n = va_arg(args, int);
	if (n >= 0)
	{
		if (flags->space)
			flags->prefix = " ";
		if (flags->plus)
			flags->prefix = "+";
	}
	else
	{
		flags->prefix = "-";
		flags->p_len = 1;
		n = -n;
	}
	if (flags->space || flags->plus)
		flags->p_len = 1;
	flags->str = ft_converter(n, 10, 0, flags);
	if (!flags->str)
		return (-1);
	set_order(flags, ft_strlen(flags->str));
	return (1);
}

int	print_unsigned(va_list args, t_flags *flags)
{
	flags->str = ft_converter(va_arg(args, unsigned int), 10, 0, flags);
	if (!flags->str)
		return (-1);
	set_order(flags, ft_strlen(flags->str));
	return (1);
}
