/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:41:47 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/13 19:58:35 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

char	*ft_null_char_case(t_data *data)
{
	char *space;

	if (data->width && data->w_val > 0)
	{
		space = ft_strndup_char(' ', data->w_val - 1);
		if (space == NULL)
			return (NULL);
		if (data->minus)
		{
			write(1, "\0", 1);
			data->null_count += 1;
			return (space);
		}
		ft_putstr(space);
		data->null_count += (int)ft_strlen(space);
		free(space);
	}
	data->null_count += 1;
	write(1, "\0", 1);
	return (ft_strdup(""));
}

char	*ft_minus_padding(char *str, t_data *data, int choice)
{
	char			*end_str;
	char			*space;
	char			*tmp;
	unsigned int	diff;

	if (choice == 1)
		diff = data->w_val - ft_strlen(str);
	else
		diff = data->p_val - ft_strlen(str) + 1;
	space = ft_strndup_char('0', diff);
	if (space == NULL)
		return (NULL);
	tmp = ft_strjoin(space, str + 1);
	free(space);
	if (tmp == NULL)
		return (NULL);
	end_str = ft_strjoin("-", tmp);
	free(tmp);
	return (end_str);
}

void	ft_truncate(char *str, unsigned int precision)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (i >= precision)
			str[i] = '\0';
		i++;
	}
}

char	*ft_precision_padding(char *str, t_data *data)
{
	char			*tmp;
	char			*space;
	unsigned int	diff;

	if (data->precision == 0)
		return (ft_strdup(str));
	else if (data->p_val == 0 && (ft_strcmp("0", str) == 0))
		return (ft_strdup(""));
	else if (data->p_val > (int)ft_strlen(str))
	{
		diff = data->p_val - (int)ft_strlen(str);
		space = ft_strndup_char('0', diff);
		if (space == NULL)
			return (NULL);
		tmp = ft_strjoin(space, str);
		free(space);
	}
	else
		tmp = ft_strdup(str);
	return (tmp);
}
