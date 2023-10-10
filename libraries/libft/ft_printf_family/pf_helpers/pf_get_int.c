/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:14:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 13:51:09 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

void	pf_get_int(va_list ap, char *tag, char **cache)
{
	int	n;

	n = va_arg(ap, int);
	*cache = ft_itoa(n);
	if (!(*cache))
		return ;
	pf_apply_zero_padding(tag, cache);
	pf_apply_precision(tag, cache, 1);
	if (n >= 0)
	{
		if (ft_strchr(tag, '+'))
			cache = ft_strmerge(cache, "+", 0);
		else if (ft_strchr(tag, ' '))
			cache = ft_strmerge(cache, " ", 0);
		pf_apply_width(tag, cache);
		return ;
	}
	*ft_strchr(*cache, '-') = (*cache)[0];
	(*cache)[0] = '-';
	pf_apply_width(tag, cache);
}
