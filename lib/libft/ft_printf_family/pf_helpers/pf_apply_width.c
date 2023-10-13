/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:14:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 13:50:59 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

void	pf_apply_width(char *tag, char **cache)
{
	size_t	i;
	int		wlen;
	char	*width;

	i = 1;
	while (ft_strchr("#0- +", tag[i]))
		i++;
	if (i == ft_strlen(tag) - 1 || tag[i] == '.')
		return ;
	wlen = ft_atoi(&tag[i]) - ft_strlen(*cache);
	if (wlen <= 0)
		return ;
	width = ft_calloc(wlen + 1, sizeof(char));
	if (!width)
		return ;
	ft_memset(width, ' ', wlen);
	cache = ft_strmerge(cache, width, !(!ft_strchr(tag, '-')));
	free(width);
}
