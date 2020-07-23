/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:08:53 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:53:31 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		*(tr + i) = f(*(s + i));
		i++;
	}
	*(tr + i) = '\0';
	return (tr);
}
