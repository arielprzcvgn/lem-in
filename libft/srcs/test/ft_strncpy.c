/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:34:49 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:53:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (*(src + i) != '\0' && i < len)
	{
		*(dst + i) = (char)*(src + i);
		i++;
	}
	while (i < len)
	{
		*(dst + i) = '\0';
		i++;
	}
	return (dst);
}
