/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:08 by arabenst          #+#    #+#             */
/*   Updated: 2023/10/10 14:59:19 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_chars(unsigned int n, int count)
{
	if (n != 0)
		return (ft_chars(n / 10, count + 1));
	return (count);
}

static int	ft_divis(int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (10 * ft_divis(power - 1));
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	int		size;
	char	*str;

	size = ft_chars(n, 0);
	if (!n)
		size++;
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = '0' + (n * ((n > 0) - (n < 0)) / ft_divis(size - i - 1)) % 10;
	return (str);
}
