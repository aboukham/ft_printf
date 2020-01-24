/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:01:01 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/24 02:48:59 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
//# include "libft.h"

# define MINUS	(1)
# define ZERO	(2)

typedef struct s_data
{
	int		minus;
	int		width;
	int		ret;
	int		stars;
	int		precision;
	int		len;
	int		min;
	int		max;
	int		index1;
	int		index2;
	char	*string;
	va_list	arg;
}				t_data;

char        *ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
int			ft_strlen(const char *s);
void			ft_putchar(char c);
int				ft_atoi(const char *s);
int		ft_printf(const char *s, ...);
char	*str_reverse(char *s);
int		ft_putstr_nbr(char *s);
void	filling_spaces(char *s, int start, int end);
int		find_number(char *s, t_data *data);
char	*ft_precision2(char *arg, t_data *data);
char	*ft_precision(char *s, t_data *data, char *arg);
char	*ft_width(char *s, t_data *data);
char	*fill_edit_arg(char *s, t_data *data);
int		print_string(char *s, t_data *data);

#endif
