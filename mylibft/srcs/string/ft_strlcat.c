/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:55:38 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:53:19 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = (size < ft_strlen(dst)) ? size : ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (length + ft_strlen((char *)src));
	while (*(src + i) != '\0' && i < size - length - 1)
	{
		*(dst + length + i) = *(src + i);
		i++;
	}
	*(dst + length + i) = '\0';
	return (length + ft_strlen((char *)src));
}
