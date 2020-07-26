/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/27 03:31:56 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(int argc, char **argv)
{
	t_in	*in;

	if (argc == 1)
		in = parsing(NULL);
	else if (argc == 2)
		in = parsing(argv[1]);
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (in == NULL)
		return (0);
	ft_printf("%s\n", in->map_buf);
	if (!pathsfinder(in) && li_free(&in, NULL, 0))
		return (0);
	li_free(&in, NULL, 0);
	return (1);
}
