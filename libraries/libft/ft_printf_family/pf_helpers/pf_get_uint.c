/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:14:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 13:51:21 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

void	pf_get_uint(va_list ap, char *tag, char **cache)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	*cache = ft_uitoa(u);
	if (!(*cache))
		return ;
	pf_apply_zero_padding(tag, cache);
	pf_apply_precision(tag, cache, 1);
	pf_apply_width(tag, cache);
}
