/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:06:19 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:55:14 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	i;
	char	*trimmed;

	if (!s)
		return (NULL);
	size = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*(s + size + 1) != '\0' && *(s + size) != '\0')
		size++;
	while (*(s + size) == ' ' || *(s + size) == '\n' ||
			*(s + size) == '\t')
		size--;
	size++;
	if ((trimmed = (char *)malloc(sizeof(*trimmed) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(trimmed + i) = *(s + i);
		i++;
	}
	*(trimmed + i) = '\0';
	return (trimmed);
}
