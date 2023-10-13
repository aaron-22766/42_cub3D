/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:17:58 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 16:45:10 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_family.h"

static void	pf_arg_to_cache(va_list ap, char *tag, char **cache)
{
	int	spec;

	spec = ft_strlen(tag) - 1;
	if (tag[spec] == 's')
		pf_get_string(ap, tag, cache);
	else if (tag[spec] == 'p')
		pf_get_pointer(ap, tag, cache);
	else if (tag[spec] == 'd' || tag[spec] == 'i')
		pf_get_int(ap, tag, cache);
	else if (tag[spec] == 'u')
		pf_get_uint(ap, tag, cache);
	else if (tag[spec] == 'x')
		pf_get_hex(ap, tag, cache, 1);
	else if (tag[spec] == 'X')
		pf_get_hex(ap, tag, cache, 0);
	else if (tag[spec] == '%')
		pf_get_percent(tag, cache);
}

//returns length of tag for skip | 0 if invaid tag | -1 if error
static int	pf_putarg(char **ret, va_list ap, const char *pos, int *prtd)
{
	int		spec;
	char	*cache;
	char	*tag;

	spec = pf_valid_tag(pos);
	if (!spec)
		return (0);
	tag = ft_calloc(spec + 2, sizeof(char));
	if (!tag)
		return (-1);
	ft_strlcpy(tag, pos, spec + 2);
	if (tag[spec] == 'c')
	{
		spec = pf_put_char_ret(ret, ap, tag, prtd);
		return (free(tag), spec);
	}
	cache = NULL;
	pf_arg_to_cache(ap, tag, &cache);
	free(tag);
	if (!cache)
		return (-1);
	if (pf_write_string_ret(ret, cache, (int)ft_strlen(cache), prtd) == -1)
		return (free(cache), -1);
	return (free(cache), spec + 1);
}

//returns number of printed characters | -1 if error
static int	pf_format_iteri(char **ret, const char *format, va_list ap)
{
	int	i;
	int	prtd;
	int	skip;

	i = 0;
	prtd = 0;
	while (format[i])
	{
		skip = pf_putarg(ret, ap, &format[i], &prtd);
		if (!skip)
			skip = pf_write_string_ret(ret, (char *)&format[i],
					(int)ft_strchr_index(&format[i], '%'), &prtd);
		if (skip < 1)
			return (skip);
		i += skip;
	}
	return (prtd);
}

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int	prtd;

	*ret = NULL;
	prtd = pf_format_iteri(ret, format, ap);
	if (prtd == -1)
	{
		free(*ret);
		*ret = NULL;
	}
	return (prtd);
}
