/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:50:16 by lfiorini          #+#    #+#             */
/*   Updated: 2023/04/23 03:30:34 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (count);
}

static	int	ft_word_len(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
		i++;
	return (i);
}

static	void	ft_copy_word(char *dst, char const *src, int *i, char c)
{
	int	k;

	k = 0;
	while (src[*i] && src[*i] != c)
		dst[k++] = src[(*i)++];
	dst[k] = '\0';
}

static	char	**ft_free(char **ans, int j)
{
	while (j >= 0)
	{
		free(ans[j]);
		j--;
	}
	free(ans);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ans = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!ans)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			ans[j] = (char *)malloc(sizeof(char) * (ft_word_len(s, c, i) + 1));
			if (!ans[j])
				return (ft_free(ans, j));
			ft_copy_word(ans[j++], s, &i, c);
		}
	}
	ans[j] = NULL;
	return (ans);
}
