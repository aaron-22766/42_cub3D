/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_write_string_ret.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:15:52 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 16:48:36 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

static char	pf_increase_ret(char **ret, int len)
{
	int		ret_len;
	char	*new;

	ret_len = 0;
	if (*ret)
		ret_len += (int)ft_strlen(*ret);
	new = ft_calloc(ret_len + len + 1, sizeof(char));
	if (!new)
		return (1);
	if (*ret)
		ft_strcpy(new, *ret);
	free(*ret);
	*ret = new;
	return (0);
}

int	pf_write_string_ret(char **ret, char *str, int len, int *prtd)
{
	if (len < 0)
		len = (int)ft_strlen(str);
	if (pf_increase_ret(ret, len))
		return (-1);
	if (str && len)
		ft_strncpy(&(*ret)[*prtd], str, len);
	*prtd += len;
	return (len);
}
