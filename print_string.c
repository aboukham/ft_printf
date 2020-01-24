/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:34:53 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/24 15:57:09 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_reverse(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

int		ft_putstr_nbr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

void	filling_spaces(char *s, int start, int end)
{
	int		i;

	i = start - 1;
	while (++i < end)
		s[i] = ' ';
	s[i] = 0;
}

int		find_number(char *s, t_data *data)
{
	int		nbr;

	if (*s == '*')
		nbr = va_arg(data->arg, int);
	else
		nbr = ft_atoi(s);
	return (nbr);
}

char	*ft_precision2(char *arg, t_data *data)
{
	int	l;

	l = ft_strlen(arg);
	if (data->precision < data->len)
	{
		if (data->minus == 1)
			filling_spaces(arg, data->precision, l);
		else
		{
			str_reverse(arg);
			data->index1 = -1;				
			while (++data->index1 < (data->len - data->precision))
				arg++;
			filling_spaces(arg, l - (data->len - data->precision), l);
			arg = str_reverse(arg);
		}
	}
	return (arg);
}

char	*ft_precision(char *s, t_data *data, char *arg)
{
	if (*s == 0)
		data->precision = 0;
	else 
	{
		if (!data->stars)
			data->precision = find_number(s, data);
		else
			data->precision = data->precision;
	}
	if (arg == NULL)
	{
		data->string = va_arg(data->arg, char *);
		data->len = ft_strlen(data->string);
		data->min = (data->precision < data->len) ? data->precision : data->len;
		if (!(arg = malloc(data->min + 1)))
			return (NULL);
		data->index1 = -1;
		while (++data->index1 < data->min)
			arg[data->index1] = data->string[data->index1];
		arg[data->index1] = 0;
	}
	else
		arg = ft_precision2(arg, data);
	return (arg);
}

char	*ft_width(char *s, t_data *data)
{
	char	*arg;

	if ( *s == '*' && *(ft_strchr(s, '.') + 1) == '*')
	{
		data->width = va_arg(data->arg, int);
		data->precision = va_arg(data->arg, int);
	}
	else
		data->width = find_number(s, data);
	arg = va_arg(data->arg, char *);
	data->len = ft_strlen(arg);
	data->max = (data->len < data->width) ? data->width : data->len;
	if (!(data->string = malloc(data->max + 1)))
		return (NULL);
	filling_spaces(data->string, 0, data->max);
	if (data->minus == 1)
	{
		data->index1 = -1;
		while (++data->index1 < data->len)
			data->string[data->index1] = arg[data->index1];
		if (data->width < data->len)
			data->string[data->index1] = 0;
	}
	else
	{
		data->index2 = data->len;
		data->index1 = ft_strlen(data->string) - 1;
		while (--data->index2 >= 0)
		{
			data->string[data->index1] = arg[data->index2];
			data->index1--;
		}
	}
	return (data->string);
}

char	*fill_edit_arg(char *s, t_data *data)
{
	char	*arg;

	data->len = 0;
	arg = NULL;
	data->stars = 0;
	if ((*s > '0' && *s <= '9') || *s == '*')
		arg = ft_width(s, data);
	if (ft_strchr(s, '.'))
	{
		if (*s == '*' && *(ft_strchr(ft_strchr(s, '.'), '*')))
			data->stars = 1;
		arg = ft_precision(ft_strchr(s, '.') + 1, data, arg);
	}
	return (arg);
}

int		print_string(char *s, t_data *data)
{
	char	*arg;

	if (*s == 0 || (*s == '-' && *(s + 1) == 0))
	{
		data->ret = ft_putstr_nbr(va_arg(data->arg, char *));
		return (data->ret);
	}
	if (*s == '-')
	{
		s++;
		data->minus = 1;
		arg = fill_edit_arg(s, data);
	}
	else
	{
		data->minus = 0;
		arg = fill_edit_arg(s, data);
	}
	data->ret = ft_putstr_nbr(arg);
	return (data->ret);
}
		
