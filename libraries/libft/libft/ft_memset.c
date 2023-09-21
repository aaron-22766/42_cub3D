/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:20:23 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/23 03:30:14 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)p;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (p = s);
}
