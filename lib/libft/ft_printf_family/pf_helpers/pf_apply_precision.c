/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:14:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 13:50:57 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

void	pf_apply_precision(char *tag, char **cache, int nu)
{
	int		i;
	size_t	plen;
	char	*new;

	i = 1;
	while (ft_strchr("#0- +", tag[i]))
		i++;
	while (ft_isdigit(tag[i]))
		i++;
	if (tag[i] != '.')
		return ;
	plen = ft_atoi(&tag[i + 1]);
	if ((!nu && plen >= ft_strlen(*cache))
		|| ((*cache)[0] != '0' && nu && plen < ft_strlen(*cache)))
		return ;
	new = ft_calloc(plen + 1 + !(!ft_strchr(*cache, '-')), sizeof(char));
	if (!new)
		return ;
	ft_memset(new, '0', nu * plen);
	if (nu && ft_strchr(*cache, '-'))
		new[0] = '-';
	ft_strlcpy(new + !(!plen) * (nu * (plen - ft_strlen(*cache) + 2
				* (new[0] == '-'))), *cache + (new[0] == '-'), plen + 1);
	free(*cache);
	*cache = new;
}
