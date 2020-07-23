/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 19:22:21 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:51:20 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		pow;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		pow = 1;
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		while (pow <= n / 10)
			pow *= 10;
		while (pow > 0)
		{
			ft_putchar_fd((n / pow) + 48, fd);
			n = n % pow;
			pow /= 10;
		}
	}
}
