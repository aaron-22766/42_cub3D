/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:16:23 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/24 04:04:10 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	parse_and_print(char **format, va_list args, t_flags *flags)
{
	int		res;

	if (**format == '\0')
		return (0);
	ft_parser(format, args, flags);
	res = print_format_arg(**format, args, flags);
	if (res == -1)
	{
		va_end(args);
		return (-1);
	}
	if (res == 1)
		free(flags->str);
	if (**format)
		(*format)++;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_flags		flags;
	char		*percent;

	flags.len = 0;
	va_start(args, format);
	while (*format)
	{
		percent = ft_strchr(format, '%');
		if (percent)
		{
			flags.len += write(1, format, percent - format);
			format = percent + 1;
			if (parse_and_print((char **)&format, args, &flags) == -1)
				return (-1);
		}
		else
		{
			flags.len += write(1, format, ft_strlen(format));
			break ;
		}
	}
	va_end(args);
	return (flags.len);
}
