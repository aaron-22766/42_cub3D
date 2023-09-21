/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:14:14 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/24 04:04:17 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_flags *flags)
{
	flags->acc = 0;
	flags->str = &c;
	set_order(flags, 1);
	return (0);
}

int	print_string(va_list args, t_flags *flags)
{
	int		len;

	flags->str = va_arg(args, char *);
	if (!flags->str)
		flags->str = ft_strdup("(null)");
	else
		flags->str = ft_strdup(flags->str);
	if (!flags->str)
		return (-1);
	len = ft_strlen(flags->str);
	if (flags->is_acc && flags->acc < len)
		len = flags->acc;
	flags->acc = 0;
	set_order(flags, len);
	return (1);
}
