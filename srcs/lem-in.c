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

char		*li_atoi(const char *str, int target)
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
		nbr != neg * farfromint || i > 12)
		return (NULL);
	target = nbr;
	return (str + i);
}

int		name_line(t_names *current, int c, int endstart, char *inst)
{
	int		i;
	char	*space;

	i = 0;
	while (inst[i] && inst[i] != ' ')
	{
		if (inst[i] == '-')
			return (0);
		i++;
	}
	inst[i] = '\0';
	if ((space = li_atoi(inst + i + 1, current->coord_x)) == NULL ||
	(space = li_atoi(space + 1, current->coord_y)) == NULL)
		return (0);
	ft_memset(inst + i, 0, space - inst + i);
	current->name = inst;
	current->startend = endstart;
	current->id = c;
	return (1);
}

char	**fill_names(t_env *e, char **inst, int c, int endstart)
{
	t_names		*current;

	if (get_next_line(0, inst) == -1 || *inst == NULL || **inst == 'L' ||
	((!ft_strcmp(*inst, "##start") && (endstart = 1)) ||
	(!ft_strcmp(*inst, "##end") && (endstart = 2)) ||
	(**inst == '#' && (endstart = 0) == 0) ||
	(current = malloc(sizeof(t_names))) == NULL ||
	(name_line(current, c, endstart, *inst) && (endstart = 0) == 0)) &&
	!ft_strchr(*inst, '-') && fill_names(e, inst, c, endstart) == NULL)
		return (NULL);
	return (1);
}

int		ants(t_env *e, char **inst)
{
	if (get_next_line(0, inst) == -1 || *inst == NULL ||
	li_atoi(*inst, e->nb_ants) == 0 || e->nb_ants < 0)
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
	(e->names = NULL) || fill_names(e, inst, 0, 0) == NULL ||
	(e->links = NULL) || fill_links(e, inst) == 0)
		return (error(e, inst, 0));
	return (1);
}
