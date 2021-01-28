/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_initiate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:06:43 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/14 11:34:12 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

unsigned int	ft_minus_zero(t_data *data, char *str)
{
	unsigned int i;

	i = 0;
	if (str[i] == '-' || str[i] == '0')
	{
		data->zero = (str[i] == '0' ? 1 : 0);
		data->minus = (str[i] == '-' ? 1 : 0);
		i++;
		if (str[i] == '-' || str[i] == '0')
		{
			if (str[i] == '0')
				data->zero = 1;
			else
				data->minus = 1;
			i++;
		}
	}
	while (ft_isbase(FLAG, str[i]))
		i++;
	return (i);
}

unsigned int	ft_width_init(t_data *data, char *str, va_list args)
{
	unsigned int i;

	i = 0;
	if (ft_isbase(DIGIT, str[i]) || str[i] == '*')
	{
		data->width = 1;
		if (str[i] == '*')
		{
			data->w_val = va_arg(args, int);
			return (++i);
		}
		else
		{
			data->w_val = ft_atoi(str + i);
			while (ft_isbase(DIGIT, str[i]))
				i++;
		}
	}
	if (data->w_val == 0)
		data->width = 0;
	return (i);
}

unsigned int	ft_precision_init(t_data *data, char *str, va_list args)
{
	unsigned int i;

	i = 0;
	if (str[i] == '.')
	{
		data->precision = 1;
		i++;
		if (str[i] == '*')
		{
			data->p_val = va_arg(args, int);
			i++;
		}
		else if (ft_isbase(DIGIT, str[i]))
		{
			data->p_val = ft_atoi(str + i);
			while (ft_isbase(DIGIT, str[i]))
				i++;
		}
		else
			data->p_val = 0;
	}
	return (i);
}

void			ft_initial_flag(t_data *data, va_list args)
{
	unsigned int	i;
	char			*str;

	i = 1;
	str = data->flag;
	i += ft_minus_zero(data, str + i);
	i += ft_width_init(data, str + i, args);
	i += ft_precision_init(data, str + i, args);
	if (!data->precision && !data->width && data->type != 'c')
	{
		data->no_flags = 1;
		return ;
	}
	if (data->p_val < 0)
		data->precision = 0;
	if (data->w_val < 0)
	{
		data->minus = 1;
		data->w_val *= -1;
	}
	if (data->minus || data->precision)
		data->zero = 0;
}

int				ft_setup_data_flag(t_data *data, const char *str, va_list args)
{
	if (!(data->flag = ft_get_flag(str)))
		return (1);
	data->type = data->flag[ft_strlen(data->flag) - 1];
	if (data->type != 'c' && data->type == data->flag[1])
	{
		data->no_flags = 1;
		return (0);
	}
	ft_initial_flag(data, args);
	return (0);
}
