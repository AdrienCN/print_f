/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:22:52 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/15 16:17:24 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

char			*ft_get_flag(const char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && i == 0)
			i++;
		if (ft_isbase(TYPE, str[i]))
			break ;
		i++;
	}
	tmp = malloc(sizeof(char) * (++i + 1));
	if (tmp == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char			*ft_strndup_char(char c, unsigned int len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

unsigned int	ft_move_on(const char *str, t_data *data)
{
	unsigned int i;

	i = 0;
	if (*str == '%')
		i = ft_strlen(data->flag);
	else
		i = ft_strlen(data->res);
	return (i);
}

char			*ft_display(const char *str)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i] != '\0' && str[i] != '%')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tmp[j] = *str;
		j++;
		str++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int				ft_isbase(char *str, char c)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
