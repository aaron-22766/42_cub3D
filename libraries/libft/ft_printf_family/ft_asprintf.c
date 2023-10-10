/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:16:50 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 14:19:06 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_family.h"

int	ft_asprintf(char **ret, const char *format, ...)
{
	int		prtd;
	va_list	ap;

	prtd = 0;
	va_start(ap, format);
	prtd = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (prtd);
}
