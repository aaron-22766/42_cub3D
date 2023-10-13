/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:14:27 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 14:33:57 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_helpers.h"

int	pf_put_char(int fd, va_list ap, char *tag, int *prtd)
{
	unsigned char	c;
	size_t			i;
	int				wlen;

	c = (unsigned char)va_arg(ap, int);
	i = 1;
	while (ft_strchr("-", tag[i]))
		i++;
	wlen = ft_atoi(&tag[i]) - 1;
	if (wlen < 0 && ft_strchr("123456789", tag[i]))
		return (-1);
	if (ft_strchr(tag, '-'))
		if (ft_putchar_fd(c, fd) == -1)
			return (-1);
	if (ft_strchr("123456789", tag[i]))
		while (wlen--)
			if (ft_putchar_fd(' ', fd) == -1)
				return (-1);
	if (!ft_strchr(tag, '-'))
		if (ft_putchar_fd(c, fd) == -1)
			return (-1);
	*prtd += !(!ft_strchr("123456789", tag[i])) * (ft_atoi(&tag[i]) - 1) + 1;
	return (ft_strlen(tag));
}
