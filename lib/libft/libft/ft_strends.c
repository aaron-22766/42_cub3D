/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strends.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:59:56 by arabenst          #+#    #+#             */
/*   Updated: 2023/10/18 14:08:00 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strends(char *str, char *sub)
{
	return (!ft_strcmp(ft_strchr(str, '\0') - ft_strlen(sub), sub));
}
