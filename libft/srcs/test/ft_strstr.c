/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:40:43 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:54:41 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*found;

	found = (char *)haystack;
	i = 0;
	if (*needle == '\0')
		return (found);
	while (*(haystack + i) != '\0')
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j))
		{
			if (*(needle + j + 1) == '\0')
				return (found + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
