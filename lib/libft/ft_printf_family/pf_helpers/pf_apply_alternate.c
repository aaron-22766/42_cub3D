/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_alternate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:14:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 13:50:43 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

void	pf_apply_alternate(char *tag, char **cache, unsigned int u)
{
	int		z;
	char	*prefix;

	if (!(ft_strchr(tag, '#') && u))
		return ;
	prefix = ft_calloc(3, sizeof(char));
	if (!prefix)
		return ;
	prefix[0] = '0';
	prefix[1] = tag[ft_strlen(tag) - 1];
	z = ((*cache)[0] == '0') + ((*cache)[0] == '0') * ((*cache)[1] == '0');
	if (z == 2 && !ft_strchr(tag, '.'))
		ft_memcpy(*cache, prefix, 2);
	else if (z == 1 && !ft_strchr(tag, '.'))
	{
		cache = ft_strmerge(cache, "0", 0);
		ft_memcpy(*cache + 1, &prefix[1], 1);
	}
	else
		cache = ft_strmerge(cache, prefix, 0);
	free(prefix);
}
