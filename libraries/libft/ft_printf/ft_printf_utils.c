/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:16:10 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/24 04:04:02 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_fill(char c, int amt, int *len)
{
	(*len) += amt;
	while (amt--)
		write(1, &c, 1);
}

static	void	set_format(t_flags *flags, int len)
{
	flags->acc = flags->acc - len;
	if (flags->acc < 0)
		flags->acc = 0;
	len += flags->acc + flags->p_len;
	flags->width = flags->width - len;
	if (flags->width < 0)
		flags->width = 0;
}

void	set_order(t_flags *flags, size_t len)
{
	set_format(flags, len);
	if (flags->minus)
	{
		flags->len += (int) write(1, flags->prefix, flags->p_len);
		print_fill(ZERO, flags->acc, &(flags->len));
		flags->len += (int) write(1, flags->str, len);
		print_fill(SPACE, flags->width, &(flags->len));
	}
	else
	{
		if (flags->zero)
		{
			flags->len += write(1, flags->prefix, flags->p_len);
			flags->p_len = 0;
		}
		print_fill(SPACE + flags->zero, flags->width, &(flags->len));
		flags->len += write(1, flags->prefix, flags->p_len);
		print_fill(ZERO, flags->acc, &(flags->len));
		flags->len += (write(1, flags->str, len));
	}
}

int	print_format_arg(char s, va_list args, t_flags *flags)
{
	char	c;

	if (s == 'c' || s == '%')
	{
		if (s == '%')
			c = '%';
		else
			c = (char)va_arg(args, int);
		return (print_char(c, flags));
	}
	if (s == 's')
		return (print_string(args, flags));
	if (flags->is_acc)
		flags->zero = 0;
	if (s == 'p')
		return (print_pointer(args, flags));
	if (s == 'd' || s == 'i')
		return (print_int(args, flags));
	if (s == 'u')
		return (print_unsigned(args, flags));
	if (s == 'x' || s == 'X')
		return (print_hex(args, flags, s == 'X'));
	if (s == 'n')
		return (save_len(args, flags->len));
	return (0);
}
