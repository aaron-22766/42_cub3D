/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_family.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:54:41 by arabenst          #+#    #+#             */
/*   Updated: 2023/10/10 14:42:45 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FAMILY_H
# define FT_PRINTF_FAMILY_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <stdarg.h>
# include "../include/libft.h"
# include "pf_helpers/pf_helpers.h"

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

// DESCRIPTION
// Writes output to stdout.
// "cspdiuxX%" are the supported conversion characters
// "-0.# +" are the supported flags (yes, space as well)
// RETURN
// Success: number of printed characters
// Fail: -1, if malloc or write failed
int	ft_printf(const char *format, ...);

// DESCRIPTION
// Writes output to stderr.
// "cspdiuxX%" are the supported conversion characters
// "-0.# +" are the supported flags (yes, space as well)
// RETURN
// Success: number of printed characters
// Fail: -1, if malloc or write failed
int	ft_eprintf(const char *format, ...);

// DESCRIPTION
// Writes output to the given file descriptor.
// "cspdiuxX%" are the supported conversion characters
// "-0.# +" are the supported flags (yes, space as well)
// RETURN
// Success: number of printed characters
// Fail: -1, if malloc or write failed
int	ft_dprintf(int fd, const char *format, ...);

// DESCRIPTION
// Writes output to the given file descriptor.
// "cspdiuxX%" are the supported conversion characters
// "-0.# +" are the supported flags (yes, space as well)
// RETURN
// Success: number of printed characters
// Fail: -1, if malloc or write failed
int	ft_vdprintf(int fd, const char *format, va_list	ap);

// DESCRIPTION
// Dynamically allocates a new string to write to.
// "cspdiuxX%" are the supported conversion characters
// "-0.# +" are the supported flags (yes, space as well)
// RETURN
// Success: number of characters written to ’*ret’
// Fail: -1, if malloc failed
int	ft_asprintf(char **ret, const char *format, ...);

// DESCRIPTION
// Dynamically allocates a new string to write to.
// "cspdiuxX%" are the supported conversion characters
// "-0.# +" are the supported flags (yes, space as well)
// RETURN
// Success: number of characters written to ’*ret’
// Fail: -1, if malloc failed
int	ft_vasprintf(char **ret, const char *format, va_list ap);

#endif
