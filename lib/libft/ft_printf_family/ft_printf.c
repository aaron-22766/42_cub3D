/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:55:14 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 12:05:52 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_family.h"

int	ft_printf(const char *format, ...)
{
	int		prtd;
	va_list	ap;

	prtd = 0;
	va_start(ap, format);
	prtd = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (prtd);
}
