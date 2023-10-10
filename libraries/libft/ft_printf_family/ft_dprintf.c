/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:36:19 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 11:38:58 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_family.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	int		prtd;
	va_list	ap;

	prtd = 0;
	va_start(ap, format);
	prtd = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (prtd);
}
