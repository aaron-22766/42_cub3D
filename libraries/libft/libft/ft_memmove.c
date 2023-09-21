/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:58:33 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/23 03:30:06 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*to;
	char	*from;

	to = (char *)dst;
	from = (char *)src;
	if (dst == src || n == 0)
		return (dst);
	if (from < to)
	{
		while (n--)
			*(to + n) = *(from + n);
		return (dst);
	}
	while (n--)
		*to++ = *from++;
	return (dst);
}
