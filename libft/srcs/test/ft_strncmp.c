/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:22:18 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:53:50 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			length;

	if (!n)
		return (0);
	length = 0;
	while (*(s1 + length) == *(s2 + length) && *(s1 + length) != '\0' &&
			*(s2 + length) != '\0' && length < n - 1)
		length++;
	return ((unsigned char)*(s1 + length) - (unsigned char)*(s2 + length));
}
