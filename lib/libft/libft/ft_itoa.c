/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:50:28 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/23 03:29:18 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_digits(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0 || n < 0)
		cnt++;
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		i;
	int		sign;

	i = ft_count_digits(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	ans = (char *)malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (NULL);
	ans[i] = '\0';
	while (i > 0)
	{
		ans[i - 1] = (n % 10) * sign + '0';
		n /= 10;
		i--;
	}
	if (sign == -1)
		ans[0] = '-';
	return (ans);
}
