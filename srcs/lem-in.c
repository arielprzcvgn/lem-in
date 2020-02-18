/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/02/12 20:37:22 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		li_atoi(const char *str, t_env *e)
{
	int		i;
	int		neg;
	int		nbr;
	long	farfromint;

	i = 0;
	farfromint = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
		neg = (str[i++] == '-') ? -1 : 1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		farfromint = farfromint * 10;
		farfromint += (str[i] - '0');
		i++;
	}
	nbr = neg * farfromint;
	if ((str[i] && (str[i] < '0' || '9' < str[i])) || nbr < 0 ||
		nbr != neg * farfromint || ft_strlen(str) > 12)
		return (0);
	e->nb_ants = nbr;
	return (1);
}

char	**fill_names(t_env *e, char **inst, int c)
{
	if (get_next_line(0, inst) == -1 || *inst == NULL || *inst)
		return (0);
	return (1);
}

int		ants(t_env *e, char **inst)
{
	if (get_next_line(0, inst) == -1 ||
	*inst == NULL || li_atoi(*inst, e) == 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	*e;
	char	**inst;

	e = NULL;
	if ((e = malloc(sizeof(t_env))) == NULL ||
	(inst = malloc(sizeof(char*))) == NULL ||
	(e->nb_ants = 0) || ants(e, inst) == 0 ||
	(e->names = NULL) || fill_names(e, inst, 0) == NULL ||
	(e->links = NULL) || fill_links(e, inst) == 0)
		return (error(e, inst, 0));
	return (1);
}
