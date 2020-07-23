/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:34:40 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:52:08 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;

	src = (char *)s;
	i = 0;
	while (*(src + i) != '\0' || c == '\0')
	{
		if (*(src + i) == c)
			return (src + i);
		i++;
	}
	return (NULL);
}
