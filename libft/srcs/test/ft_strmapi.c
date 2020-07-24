/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:08:53 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:53:37 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
		i++;
	if ((tr = (char *)malloc(sizeof(*tr) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(tr + i) = f(i, *(s + i));
		i++;
	}
	*(tr + i) = '\0';
	return (tr);
}
