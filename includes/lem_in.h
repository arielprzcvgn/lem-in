/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:58:18 by seimori           #+#    #+#             */
/*   Updated: 2020/06/19 17:51:23 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

/*
**	for open //BONUS pour lire depuis un fichier
*/
# include <fcntl.h>

# define INF 0x7FFFFFFF

# define BUFF_SIZE 64000

typedef struct		s_queue
{
	int				in;
	int				score;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_room
{
	int				id;
	int				x;
	int				y;
	char			*name;
	int				score;
	struct s_room	*next;
	struct s_room	*previous;
	int				ants;
}					t_room;

typedef struct		s_ant
{
	int				turn;
	t_room			*path;
}					t_ant;

typedef struct		s_in
{
	int				fd;
	char			*map_buf;
	int				ant_size;
	int				nb_room;
	t_room			*room;
	t_room			*start_room;
	t_room			*end_room;
	int				**matrix;
	int				**oriented;
	int				max_paths;
	t_room			**path;
	int				max_best;
	t_room			**best;
	t_ant			*ants;
}					t_in;

/*
**	parsing.c
*/
t_in				*parsing(char *pathname);
void				print_links(t_in *e);

/*
**	parse_tools.c
*/
t_room				*li_lstnew(void);
char				*get_name(char *str);
char				*li_atoi(char *str, int *target, int stop);
int					clean_room_list(t_in *e, t_room *mem);
char				*ft_strstopchr(char *s, int c, int stop);

/*
**	parse_fill.c
*/
int					fill_links(t_in *e, char **inst, t_room *mem);
int					fill_names(t_in *e, char **inst, t_room **mem);

/*
**	li_free.c
*/
int					free_room_list(t_room **mem, int max, int room);
int					li_free(t_in **e, char **inst, int err);

/*
**	pathsfinder.c
*/
int					pathsfinder(t_in *in);
t_room				*li_lstcpy(t_room *dst);

/*
**	suurballe.c
*/
int					oriented_bfs(t_in *in);

/*
**	print_result.c
*/
void				init_ant(t_in *in, t_ant *ants);
int					simple_bfs(t_in *in);
int					print_ant(t_in *in);

/*
**	algo_tools.c
*/
t_queue				*free_queue(t_queue *q);
t_queue				*add_queue(int in, int score, t_queue *next);
void				order_path(t_in *in);
void				print_oriented(t_in *e);
void				print_path(t_in *in);

#endif
