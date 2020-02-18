/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:54 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:09:19 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>

# define BUFF_SIZE 500

typedef struct		s_env
{
	int		nb_ants;
	char	**names;
	int		**links;

}					t_env;

/*
**Initialisation (init.c)
*/


/*
**Visualisation (visu.c)
*/


/*
**Free functions (li_free.c)
*/


/*
**libft
*/
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strlen(const char *s);
void				ft_strclr(char *s);
char				*ft_strjoinfree(char *s1, char *s2, int frees1, int frees2);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_bzero(void *b, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					get_next_line(const int fd, char **line);
char				**ft_strsplit(char const *s, char c);
int					ft_printf(const char *format, ...);

#endif
