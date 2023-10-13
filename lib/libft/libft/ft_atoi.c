/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:33:54 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/24 04:26:03 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		s;

	i = 0;
	n = 0;
	s = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((n * 10 + (str[i] - '0')) / 10 != n && s == -1)
			return (0);
		else if ((n * 10 + (str[i] - '0')) / 10 != n)
			return (-1);
		n = n * 10 + str[i] - '0';
		i++;
	}
	return ((int)(n * s));
}
