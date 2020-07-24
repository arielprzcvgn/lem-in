/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:52:28 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:53:06 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*join;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((join = (char *)malloc(sizeof(*join) * (size + 1))) == NULL)
		return (NULL);
	if ((str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	join = ft_strcat(str, s2);
	return (join);
}
