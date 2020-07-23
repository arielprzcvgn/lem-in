/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:40:43 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:54:15 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*found;

	found = (char *)haystack;
	i = 0;
	if (*needle == '\0')
		return (found);
	while (*(haystack + i) != '\0' && i < len)
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j) && (i + j) < len)
		{
			if (*(needle + j + 1) == '\0')
				return (found + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
