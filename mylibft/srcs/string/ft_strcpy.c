/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:28:15 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:52:19 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dst + i) = (char)*(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}