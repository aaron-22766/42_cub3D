/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:14:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 13:51:15 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

void	pf_get_pointer(va_list ap, char *tag, char **cache)
{
	unsigned long	p;

	p = (unsigned long)va_arg(ap, void *);
	*cache = ft_ultoa_hex(p, 1);
	if (!(*cache))
		return ;
	if (!ft_strmerge(cache, "0x", 0))
	{
		free(*cache);
		*cache = NULL;
		return ;
	}
	pf_apply_width(tag, cache);
}
