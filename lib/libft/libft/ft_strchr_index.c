/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:47:39 by arabenst          #+#    #+#             */
/*   Updated: 2023/05/29 10:47:58 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

ssize_t	ft_strchr_index(const char *s, int c)
{
	ssize_t	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return (i);
	if ((char)c == '\0')
		return (i);
	return (-1);
}
