/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:36:26 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/23 03:32:25 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[i + j])
		j++;
	while (j && ft_strchr(set, s1[i + j - 1]))
		j--;
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	while (k < j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
