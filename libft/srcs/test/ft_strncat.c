/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:05:29 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:53:44 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	char		*copy;

	copy = (char *)s2;
	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	j = 0;
	while (*(copy + j) != '\0' && j < n)
	{
		*(s1 + i + j) = *(copy + j);
		j++;
	}
	*(s1 + i + j) = '\0';
	return (s1);
}
