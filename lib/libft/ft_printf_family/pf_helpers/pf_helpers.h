/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helpers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:48:30 by arabenst          #+#    #+#             */
/*   Updated: 2023/06/01 16:05:08 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HELPERS_H
# define PF_HELPERS_H

/* ************************************************************************** */
/*                                  INCLUDE                                   */
/* ************************************************************************** */

# include "../ft_printf_family.h"

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

// pf_get_string.c
void	pf_get_string(va_list ap, char *tag, char **cache);

// pf_get_int.c
void	pf_get_int(va_list ap, char *tag, char **cache);

// pf_get_uint.c
void	pf_get_uint(va_list ap, char *tag, char **cache);

// pf_get_hex.c
void	pf_get_hex(va_list ap, char *tag, char **cache, int lowercase);

// pf_get_pointer.c
void	pf_get_pointer(va_list ap, char *tag, char **cache);

// pf_get_percent.c
void	pf_get_percent(char *tag, char **cache);

// pf_put_char.c
int		pf_put_char(int fd, va_list ap, char *tag, int *prtd);

// pf_put_char_ret.c
int		pf_put_char_ret(char **ret, va_list ap, char *tag, int *prtd);

// pf_write_string_ret.c
int		pf_write_string_ret(char **ret, char *str, int len, int *prtd);

// pf_apply_width.c
void	pf_apply_width(char *tag, char **cache);

// pf_apply_precision.c
void	pf_apply_precision(char *tag, char **cache, int nu);

// pf_apply_zero_padding.c
void	pf_apply_zero_padding(char *tag, char **cache);

// pf_apply_alternate.c
void	pf_apply_alternate(char *tag, char **cache, unsigned int u);

// pf_valid_tag.c
//returns index of specifier in tag | 0 if invalid
int		pf_valid_tag(const char *tag);

#endif