/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_valid_tag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:14:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 13:51:27 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

//returns index of specifier in tag | 0 if invalid
int	pf_valid_tag(const char *tag)
{
	int	i;

	if (tag[0] != '%')
		return (0);
	i = 1;
	while (ft_strchr("#0- +", tag[i]))
		i++;
	while (ft_isdigit(tag[i]))
		i++;
	if (tag[i] == '.')
	{
		i++;
		while (ft_isdigit(tag[i]))
			i++;
	}
	if (ft_strchr("cspdiuxX%", tag[i]))
		return (i);
	return (0);
}
