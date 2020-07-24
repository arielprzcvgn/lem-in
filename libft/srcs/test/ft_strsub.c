/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:32:47 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:54:47 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*part;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	if ((part = (char *)malloc(sizeof(*part) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		*(part + i) = *(s + (size_t)start + i);
		i++;
	}
	*(part + i) = '\0';
	return (part);
}
