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

void	retrace_path(t_in *in, int room)
{
	int		tmp;
	int		prev;

	in->oriented[(in->nb_room - 1) * 2 - 1][room] = -1;
	in->oriented[room][(in->nb_room - 1) * 2 - 1] = 0;
	in->matrix[room / 2][in->nb_room - 1] = 1;
	in->matrix[in->nb_room - 1][room / 2] = -1;
	prev = (in->nb_room - 1) * 2 - 1;
	while (room)
	{
		tmp = (in->oriented[room][0] < 0 ? 0 : in->oriented[room][0]);
		in->oriented[room][tmp] = -1;
		in->oriented[tmp][room] = 0;
		if (tmp + (tmp % 2) != room + (room % 2))
		{
			in->matrix[(tmp + (tmp % 2)) / 2][(room + (room % 2)) / 2] += 1;
			in->matrix[(room + (room % 2)) / 2][(tmp + (tmp % 2)) / 2] += -1;
			in->oriented[room][prev] == 1 ? in->oriented[room][prev] = 1 : 0;
			prev = room;
		}
		room = (in->oriented[room][0] < 0 ? 0 : in->oriented[room][0]);
	}
	tmp = 0;
	while (++tmp < (in->nb_room - 1) * 2)
		in->oriented[tmp][0] = (in->oriented[tmp][0] == -1 ? -1 : 0);
}

t_queue	*explore_room(t_in *in, t_queue **to_visit, t_queue *tmp)
{
	int			j;
	t_queue		*end_visit;

	j = 0;
	while (++j <= (in->nb_room - 2) * 2)
	{
		if ((in->oriented[(*to_visit)->in][j] == 1 ||
			in->oriented[(*to_visit)->in][j] == -1) && in->oriented[j][0] == 0)
		{
			end_visit = *to_visit;
			while (in->oriented[(*to_visit)->in][j] == 1 &&
									end_visit->next != NULL)
				end_visit = end_visit->next;
			tmp = (*to_visit)->next;
			if ((end_visit->next = add_queue(j,
			(*to_visit)->score + in->oriented[(*to_visit)->in][j],
			(in->oriented[(*to_visit)->in][j] == -1 ? tmp : NULL))) == NULL)
				return (free_queue(*to_visit));
			in->oriented[j][0] = ((*to_visit)->in == 0 ? -3 : (*to_visit)->in);
		}
	}
	end_visit = (*to_visit)->next;
	free(*to_visit);
	*to_visit = NULL;
	return (end_visit);
}

int		oriented_bfs(t_in *in)
{
	t_queue		*to_visit;

	if ((to_visit = add_queue(0, 2, NULL)) == NULL)
		return (0);
	while (to_visit)
	{
		if (in->oriented[to_visit->in][(in->nb_room - 1) * 2 - 1])
		{
			retrace_path(in, to_visit->in);
			free_queue(to_visit);
			return (1);
		}
		to_visit = explore_room(in, &to_visit, NULL);
	}
	free_queue(to_visit);
	return (0);
}
