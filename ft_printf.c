/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:21:16 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/24 03:16:56 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char *t = "cspdiuxX";

int		check_specif(char *s, t_data *data, char c)
{
	/*if (c == 'd' || c == 'i' || c == 'u')
		data->ret = data->ret + print_integer(s, data, c);*/
	if (c == 's')
		data->ret = data->ret + print_string(s, data);
	/*if (c == 'c')
		data->ret = data->ret + print_character(s, data, c);
	if (c == 'x' || c == 'X')
		data->ret = data->ret + print_hexadicimal(s, data, c);
	if (c == 'p')
		data->ret = data->ret + print_adress(s, data);*/
	return (data->ret);
}

void	get_arg(char *s, t_data *data, int *i, int *index)
{
	int		j;

	//data->t[10] = "cspdiuxX";
	while (s[*i])
	{
		j = 0;
		while (t[j] && t[j] != s[*i])
			j++;
		if (t[j] == s[*i])
		{
			check_specif(ft_substr((const char *)s, (unsigned int)*index, (size_t)*i), data, t[j]);
			break ;
		}
		(*i)++;
	}	
}

void	ft_strparsing(char *s, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s == '%')
		{
			get_arg(s + 1, data, &i, &j);
			s = s + i + 1;
			j = j + i + 1;
		}
		else
		{
			ft_putchar(*s);
			data->ret = data->ret + 1;
		}
		s++;
		j++;
	}
}

int		ft_printf(const char *s, ...)
{
	t_data	data;

	data.ret = 0;
	//data.format_str = (char *)s;
	va_start(data.arg, s);
	ft_strparsing((char *)s, &data);
	va_end(data.arg);
	return (data.ret);
}
