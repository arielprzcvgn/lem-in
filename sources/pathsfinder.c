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

t_room	*li_lstcpy(t_room *dst)
{
	t_room	*new;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	new->id = dst->id;
	new->x = dst->x;
	new->y = dst->y;
	new->name = dst->name;
	new->score = 0;
	new->next = NULL;
	new->previous = NULL;
	new->ants = 0;
	return (new);
}

int		init_oriented(t_in *in)
{
	int		i;
	int		j;

	i = -1;
	if (!(in->oriented = malloc(sizeof(int*) * (in->nb_room - 1) * 2)))
		return (0);
	while (++i < (in->nb_room - 1) * 2)
	{
		if (!(in->oriented[i] = malloc(sizeof(int*) * (in->nb_room - 1) * 2)))
			return (0);
		j = -1;
		while (++j < (in->nb_room - 1) * 2)
			in->oriented[i][j] = 0;
	}
	i = -1;
	while (++i < in->nb_room - 1)
	{
		j = 0;
		while (++j < in->nb_room &&
					((in->oriented[i * 2][j * 2 - 1] = in->matrix[i][j]) || 1))
			if (j + 1 < in->nb_room)
				in->oriented[i * 2 + 1][i * 2 + 2] = 1;
	}
	return (1);
}

int		pathsfinder(t_in *in)
{
	int		i;
	int		j;
	t_ant	*ants;

	if ((i = -1) && !init_oriented(in))
		return (0);
	while (++i < in->nb_room && (j = -1))
		while (++j < in->nb_room)
			in->matrix[i][j] = 0;
	in->max_paths = 0;
	while (oriented_bfs(in))
	{
		in->max_paths++;
		if (!simple_bfs(in))
			return (0);
		order_path(in);
		if ((ants = malloc(sizeof(t_ant) * in->ant_size)) == NULL)
			return (0);
		init_ant(in, ants);
	}
	if (in->max_paths && print_ant(in))
		return (1);
	write(2, "NO PATH FOUND\n", 14);
	return (0);
}
