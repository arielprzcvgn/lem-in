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

t_queue	*free_queue(t_queue *q)
{
	t_queue	*tmp;

	while (q)
	{
		tmp = q;
		q = q->next;
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

t_queue	*add_queue(int in, int score, t_queue *next)
{
	t_queue	*to_visit;

	if ((to_visit = malloc(sizeof(t_queue))) == NULL)
		return (NULL);
	to_visit->in = in;
	to_visit->score = score;
	to_visit->next = next;
	return (to_visit);
}

void	order_path(t_in *in)
{
	int		order;
	int		i;
	t_room	*tmp;

	order = 1;
	while (order)
	{
		order = 0;
		i = -1;
		while (++i < in->max_paths - 1)
		{
			if (in->path[i]->score > in->path[i + 1]->score)
			{
				tmp = in->path[i];
				in->path[i] = in->path[i + 1];
				in->path[i + 1] = tmp;
				order = 1;
			}
		}
	}
}

void	print_path(t_in *in)
{
	int		i;
	t_room	*tmp;

	i = -1;
	while (++i < in->max_paths)
	{
		tmp = in->path[i];
		ft_printf("PATH NB : %i  len:%i  =>  ", i, tmp->score);
		while (tmp)
		{
			ft_printf("%i : %s /// ", tmp->id, tmp->name);
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}

void	print_oriented(t_in *e)
{
	int		i;
	int		j;
	t_room	*current;

	i = -1;
	ft_printf("\n                ");
	while (++i < (e->nb_room - 1) * 2)
		ft_printf("[%3i]", i);
	ft_printf("\n");
	i = -1;
	current = e->room;
	while (++i < (e->nb_room - 1) * 2)
	{
		ft_printf("%8.10s [%3i]:", current->name, i);
		j = -1;
		while (++j < (e->nb_room - 1) * 2)
			ft_printf("  %3i", e->oriented[i][j]);
		if (i == 0)
			ft_printf("  START");
		else if (e->end_room->id * 2 - 1 == i)
			ft_printf("  END");
		ft_printf("\n");
		if (i % 2 == 0)
			current = current->next;
	}
}
