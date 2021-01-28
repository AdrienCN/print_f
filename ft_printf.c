/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:14:28 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/14 11:39:28 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_data	data;
	int		result;

	ft_init_datablock(&data);
	va_start(args, str);
	result = ft_printf_loop(str, args, &data);
	if (result == -1)
		ft_reset_datablock(&data);
	va_end(args);
	return (result);
}

int		ft_printf_loop(const char *str, va_list args, t_data *data)
{
	unsigned int	printed;

	printed = 0;
	while (*str)
	{
		if (*str == '%')
			data->res = ft_conversion(str, args, data);
		else
			data->res = ft_display(str);
		if (data->res == NULL)
			return (-1);
		str += ft_move_on(str, data);
		printed += ft_strlen(data->res) + data->null_count;
		ft_putstr(data->res);
		ft_reset_datablock(data);
	}
	return (printed);
}

char	*ft_apply_flag_output(char *str, t_data *data)
{
	if (data->type == 'c' || data->type == '%' || data->type == 'p')
		return (ft_display_char(str, data));
	else if (data->type == 's')
		return (ft_display_str(str, data));
	else if (ft_isbase("xXu", data->type))
		return (ft_display_hex(str, data));
	else if (ft_isbase("di", data->type))
		return (ft_display_nbr(str, data));
	return (NULL);
}

char	*ft_conversion(const char *str, va_list args, t_data *data)
{
	char *tmp;
	char *end_str;

	tmp = NULL;
	end_str = NULL;
	if (ft_check_conversion_format(str))
		return (NULL);
	if (ft_setup_data_flag(data, str, args))
		return (NULL);
	tmp = ft_make_initial_string(*data, args);
	if (tmp == NULL || data->no_flags == 1)
		return (tmp);
	end_str = ft_apply_flag_output(tmp, data);
	free(tmp);
	return (end_str);
}

char	*ft_make_initial_string(t_data data, va_list args)
{
	char *tmp;

	tmp = NULL;
	if (data.type == '%')
		tmp = ft_chardup('%');
	if (data.type == 'c')
		tmp = ft_chardup(va_arg(args, int));
	else if (data.type == 's')
		tmp = ft_strdup(va_arg(args, char *));
	else if (data.type == 'd' || data.type == 'i')
		tmp = ft_itoa_base_dup(va_arg(args, int), DIGIT);
	else if (data.type == 'u')
		tmp = ft_u_itoa_base_dup(va_arg(args, unsigned int), DIGIT);
	else if (data.type == 'x')
		tmp = ft_u_itoa_base_dup(va_arg(args, unsigned int), HEX_MIN);
	else if (data.type == 'X')
		tmp = ft_u_itoa_base_dup(va_arg(args, unsigned int), HEX_MAJ);
	else if (data.type == 'p')
		tmp = ft_address_dup(va_arg(args, void *), HEX_MIN, data);
	return (tmp);
}
