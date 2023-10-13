/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:13:07 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 14:13:32 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_family.h"

int	ft_eprintf(const char *format, ...)
{
	int		prtd;
	va_list	ap;

	prtd = 0;
	va_start(ap, format);
	prtd = ft_vdprintf(STDERR_FILENO, format, ap);
	va_end(ap);
	return (prtd);
}
