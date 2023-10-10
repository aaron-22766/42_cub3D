/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:13:47 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 13:51:18 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

void	pf_get_string(va_list ap, char *tag, char **cache)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	*cache = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!(*cache))
		return ;
	ft_strlcpy(*cache, str, ft_strlen(str) + 1);
	pf_apply_precision(tag, cache, 0);
	pf_apply_width(tag, cache);
}
