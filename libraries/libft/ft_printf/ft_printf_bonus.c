/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:16:01 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/24 04:03:59 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	save_len(va_list args, int len)
{
	int	*n;

	n = va_arg(args, int *);
	*n = len;
	return (0);
}
