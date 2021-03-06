/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/06/19 18:29:36 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*li_lstnew(void)
{
	t_room	*new;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	new->id = -1;
	new->x = 0;
	new->y = 0;
	new->name = NULL;
	new->score = INF;
	new->next = NULL;
	new->previous = NULL;
	new->ants = 0;
	return (new);
}

char	*get_name(char *str)
{
	int		i;
	char	*dst;
	char	tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != ' ')
		i++;
	if (str[i] == '\n')
		return ((dst = ft_strdup(str)) ? dst : NULL);
	tmp = str[i];
	str[i] = '\0';
	if (!(dst = ft_strdup(str)))
		return (NULL);
	str[i] = tmp;
	return (dst);
}

char	*ft_strstopchr(char *s, int c, int stop)
{
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0' && s[i] != stop)
		i++;
	if (s[i] == c || c == '\0')
		return (s + i);
	else
		return (NULL);
}

char	*li_atoi(char *str, int *target, int stop)
{
	int		i;
	int		neg;
	int		nbr;
	long	farfromint;

	if (!str)
		return (NULL);
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
	nbr != neg * farfromint || i > 12)
		return (NULL);
	*target = nbr;
	return (str + i);
}

int		clean_room_list(t_in *e, t_room *mem)
{
	if ((e->nb_room = mem->id + 2) == 1 || !e->end_room ||
	e->end_room->id == -1 || !e->start_room || e->start_room->id == -1)
		return (0);
	e->start_room->id = 0;
	e->start_room->score = 0;
	e->end_room->id = e->nb_room - 1;
	mem = e->room;
	while (mem)
	{
		while (mem->next == e->end_room || mem->next == e->start_room)
			mem->next = mem->next->next;
		if (mem->next == NULL && mem != e->end_room &&
			(mem->next = e->end_room))
			e->end_room->next = NULL;
		mem = mem->next;
	}
	e->start_room->next = e->room->next;
	free(e->room);
	e->room = e->start_room;
	return (e->room->score == 0 ? 1 : 0);
}
