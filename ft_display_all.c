/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:40:17 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/13 20:16:10 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

char	*ft_display_hex(char *str, t_data *data)
{
	char *tmp;
	char *stock;
	char *space;
	char x;

	if (!(tmp = ft_precision_padding(str, data)))
		return (NULL);
	if (data->width && data->w_val > (int)ft_strlen(tmp))
	{
		x = (data->zero == 1 ? '0' : ' ');
		if (!(space = ft_strndup_char(x, data->w_val - (int)ft_strlen(tmp))))
		{
			free(tmp);
			return (NULL);
		}
		stock = tmp;
		if (data->minus)
			tmp = ft_strjoin(tmp, space);
		else
			tmp = ft_strjoin(space, tmp);
		free(space);
		free(stock);
	}
	return (tmp);
}

char	*ft_display_str(char *str, t_data *data)
{
	char			*tmp;
	char			*space;

	if (data->precision && (int)ft_strlen(str) > data->p_val)
		ft_truncate(str, data->p_val);
	if (data->width && data->w_val > (int)ft_strlen(str))
	{
		if (!(space = ft_strndup_char(' ', (data->w_val - ft_strlen(str)))))
			return (NULL);
		if (data->minus)
			tmp = ft_strjoin(str, space);
		else
			tmp = ft_strjoin(space, str);
		free(space);
	}
	else
		tmp = ft_strdup(str);
	return (tmp);
}

char	*ft_display_char(char *str, t_data *data)
{
	char			*space;
	char			*tmp;
	char			a;
	unsigned int	diff;

	if (data->type == 'c' && ft_strlen(str) == 0)
		return (ft_null_char_case(data));
	if (data->width && data->w_val > (int)ft_strlen(str))
	{
		diff = data->w_val - ft_strlen(str);
		a = ((data->type == '%' && data->zero == 1) ? '0' : ' ');
		if (!(space = ft_strndup_char(a, diff)))
			return (NULL);
		if (data->minus)
			tmp = ft_strjoin(str, space);
		else
			tmp = ft_strjoin(space, str);
		free(space);
	}
	else
		tmp = ft_strdup(str);
	return (tmp);
}

char	*ft_display_nbr(char *str, t_data *data)
{
	int		nbr;
	char	*tmp;
	char	*save;

	nbr = ft_atoi(str);
	if (nbr < 0)
	{
		if (data->precision && data->p_val > (int)ft_strlen(str + 1))
		{
			tmp = ft_minus_padding(str, data, 0);
			save = tmp;
			tmp = ft_display_hex(tmp, data);
			free(save);
			return (tmp);
		}
		else if (data->zero == 1)
		{
			if (data->width && data->w_val > (int)ft_strlen(str))
				return (ft_minus_padding(str, data, 1));
		}
	}
	tmp = ft_display_hex(str, data);
	return (tmp);
}
