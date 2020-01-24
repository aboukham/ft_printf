/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:41:02 by aaboukha          #+#    #+#             */
/*   Updated: 2019/11/07 20:31:33 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_allocation(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
		len = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (str);
}

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	str = ft_allocation(s, start, len);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && i < start)
		i++;
	if (i != start)
		str[0] = 0;
	else
	{
		j = 0;
		while (s[i] && j < len)
		{
			str[j++] = s[i];
			i++;
		}
		str[j] = 0;
	}
	return (str);
}
