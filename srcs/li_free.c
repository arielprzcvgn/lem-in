/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

/*char	**copy_tab(char **tab, char **argv, int argc, int i)
{
	int		j;

	j = 0;
	if ((tab = malloc(sizeof(*tab) * (argc - i + 1))) == NULL)
		return (NULL);
	while (i + j < argc)
	{
		if ((tab[j] = ft_strdup(argv[i + j])) == NULL)
			return (NULL);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
*/
int		free_mat(int **mat)
{
	int		i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (1);
}

int		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

int		error(t_env *e, char **inst, int err)
{
	if (err)
		write(2, "Error\n", 6);
	if (e && ((e->names && free_tab(e->names)) ||
	(e->links && free_mat(e->links)) || 1))
		free(e);
	if (inst)
		free_tab(inst);
	return (err);
}
