/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:32:50 by ariperez          #+#    #+#             */
/*   Updated: 2019/09/03 23:09:31 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

# define TROPHY			' '

# define MINUS			(1 << 0)
# define ZERO			(1 << 1)
# define PLUS			(1 << 2)
# define SPACE			(1 << 3)
# define HASH			(1 << 4)
# define HASH0			(1 << 5)
# define APOS			(1 << 6)
# define PRECI			(1 << 7)
# define H				(1 << 8)
# define HH				(1 << 9)
# define L				(1 << 10)
# define LL				(1 << 11)
# define J				(1 << 12)
# define Z				(1 << 13)
# define LLL			(1 << 14)

typedef struct		s_argument
{
	short			p;
	int				width;
	int				precision;
	char			*arg;
	int				neg;
	int				sign;
	int				zeros;
	int				str;
	int				space;
}					t_argument;

typedef struct		s_printf
{
	char			*format;
	int				printed;
	char			*buffer;
	int				c;
	va_list			ap;
	t_argument		a;
}					t_printf;

int					ft_printf(const char *format, ...);
char				*specifier(t_printf *p);

char				*parse(t_printf *p);
void				precision(t_printf *p);
void				width(t_printf *p);

int					itoa_printf(intmax_t n, t_printf *p);
char				*uitoa_printf(uintmax_t n, t_printf *p, int b, char *base);
char				*ft_ulltoa(unsigned long long n);
int					ftoa_printf(long double n, t_printf *p);
void				apostrophe(t_printf *p);

int					put_d_i(t_printf *p);
int					put_o(t_printf *p, unsigned long o);
int					put_u(t_printf *p, unsigned long u);
int					put_x(t_printf *p, unsigned long x);
int					put_f(t_printf *p);
int					put_c(t_printf *p, char *s);

int					speci_d_i(t_printf *p);
int					speci_o(t_printf *p);
int					speci_u(t_printf *p);
int					speci_x(t_printf *p);
int					speci_f(t_printf *p);
int					speci_c(t_printf *p, int pc);
int					speci_s(char *cpy, t_printf *p);
int					speci_p(void *pointeur, t_printf *p);

#endif
