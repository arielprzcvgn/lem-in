/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitcharset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:47:41 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:54:35 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		sep(char s, char *charset)
{
	int		i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static int		fill(char **splited, const char *s, int size, char *charset)
{
	size_t		nbwrd;
	size_t		i;

	i = size;
	nbwrd = 0;
	while (*(s + i) != '\0')
	{
		size = i;
		while (!sep(*(s + i), charset) && *(s + i) != '\0')
			i++;
		if ((*(splited + nbwrd) =
					(char *)malloc(sizeof(**splited) * (i - size))) == NULL)
			return (0);
		i = size;
		while (!sep(*(s + i), charset) && *(s + i) != '\0')
		{
			splited[nbwrd][i - size] = *(s + i);
			i++;
		}
		splited[nbwrd][i - size] = '\0';
		while (sep(*(s + i), charset) && *(s + i) != '\0')
			i++;
		nbwrd++;
	}
	return (1);
}

char			**ft_strsplitcharset(char const *s, char *charset)
{
	char		**splited;
	size_t		nbwords;
	size_t		size;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	while (sep(*(s + i), charset) && i < ft_strlen(s))
		i++;
	size = i;
	nbwords = 0;
	while (*(s + i) != '\0')
	{
		if (!sep(*(s + i), charset) && sep(*(s + i + 1), charset))
			nbwords++;
		i++;
	}
	if ((splited = (char **)malloc(sizeof(*splited) * (nbwords + 1))) == NULL ||
		fill(splited, s, size, charset) == 0)
		return (NULL);
	splited[nbwords] = 0;
	return (splited);
}
