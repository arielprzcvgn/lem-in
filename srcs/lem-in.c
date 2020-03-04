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

char		*li_atoi(char *str, int *target, int stop)
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
	if (i == 0 || (str[i] != stop && (str[i] < '0' || '9' < str[i])) ||
	nbr < 0 || nbr != neg * farfromint || i > 12)
		return (NULL);
	*target = nbr;
	return (str + i);
}

int		check_name(t_env *e, char *name)
{
	int		i;

	i = 0;
	while (i < e->nb_room)
	{
		if (ft_strcmp(e->names[i].name, name) == 0)
			return (e->names[i].id);
		i++;
	}
	return (-1);
}

int		init_links(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	if (!(e->links = malloc(sizeof(int*) * e->nb_room)))
		return (0);
	while (++i < e->nb_room)
		if (!(e->links[i] = malloc(sizeof(int*) * e->nb_room)))
			return (0);
	i = -1;
	while (++i < e->nb_room)
	{
		j = -1;
		while (++j < e->nb_room)
			e->links[i][j] = 0;
	}
	return (1);
}

void	print_links(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->nb_room)
	{
		ft_printf("%s :", e->names[i].name);
		j = -1;
		while (++j < e->nb_room)
			ft_printf("  %i", e->links[i][j]);
		ft_printf("\n");
	}
}

int		fill_links(t_env *e, char **inst, int first)
{
	char	*dash;
	int		id_room1;
	int		id_room2;

	if (!init_links(e))
		return (0);
	while ((first && !(first = 0)) || get_next_line(0, inst) == 1)
	{
		if (**inst != '#')
		{
			if (*inst == NULL || !(dash = ft_strchr(*inst, '-')))
				break ;
			*dash = '\0';
			if (ft_strchr(dash + 1, '\n'))
				*ft_strchr(dash + 1, '\n') = '\0';
			if ((id_room1 = check_name(e, *inst)) == -1 ||
			(id_room2 = check_name(e, dash + 1)) == -1)
				break ;
			e->links[id_room1][id_room2] = 1;
			e->links[id_room2][id_room1] = 1;
		}
	}
	return (1);
}

t_names		name_line(int c, int cmd, char *inst)
{
	int		i;
	char	*space;
	t_names	n;

	i = 0;
	while (inst[i] && inst[i] != ' ')
	{
		if (inst[i] == '-')
			n.id = -1;
		i++;
	}
	inst[i] = '\0';
	if (((space = li_atoi(inst + i + 1, &n.x, ' ')) == NULL ||
	(space = li_atoi(space + 1, &n.y, '\n')) == NULL) && (n.id = -1))
		return (n);
	ft_memset(inst + i, 0, space - inst + i);
	n.name = inst;
	n.startend = cmd;
	n.id = (n.id == -1 ? -1 : c);
	return (n);
}

int		fill_names(t_env *e, char **inst, int c, int cmd)
{
	t_names		n;

	if (get_next_line(0, inst) == -1 || *inst == NULL || **inst == 'L' ||
	(!ft_strcmp(*inst, "##end\n") && fill_names(e, inst, c, 2) == 0) ||
	(!ft_strcmp(*inst, "##start\n") && fill_names(e, inst, c, 1) == 0) ||
	(**inst == '#' && fill_names(e, inst, c, cmd)) ||
	((n = name_line(c, cmd, *inst)).id != -1 && fill_names(e, inst, c + 1, 0) == 0))
		;
	if (!(e->names) && ((e->nb_room = c) || 1) && (cmd = 1) &&
	!(e->names = malloc(sizeof(t_names) * c - 1)))
		return (0);
	if (!cmd)
		e->names[c] = n;
	return (1);
}

int		ants(t_env *e, char **inst)
{
	//COMMENTAIRE EN PREMIERE LIGNE
	if (get_next_line(0, inst) == -1 || *inst == NULL ||
	li_atoi(*inst, &e->nb_ants, '\n') == 0 || e->nb_ants < 0)
		return (0);
	return (1);
}

int		read_map(t_env *e, char **inst)
{
	e->nb_ants = 0;
	e->nb_room = 0;
	e->names = NULL;
	e->links = NULL;
	if (ants(e, inst))
		if (fill_names(e, inst, 0, 0))
			fill_links(e, inst, 1);
	print_links(e);
	return (1);
}

int		main(void)
{
	t_env	*e;
	char	**inst;

	e = NULL;
	inst = NULL;
	if ((e = malloc(sizeof(t_env))) == NULL ||
	(inst = malloc(sizeof(char*))) == NULL || read_map(e, inst) == 0)
		return (error(e, inst, 1));
	return (1);
}
