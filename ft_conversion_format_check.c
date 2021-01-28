/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_format_check.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:24:13 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/14 11:26:53 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

unsigned int	ft_flag_format(const char *str)
{
	unsigned int i;

	i = 0;
	if (str[i] == '%')
		i++;
	if (ft_isbase(FLAG, str[i]))
		i++;
	if (ft_isbase(FLAG, str[i]))
		i++;
	while (ft_isbase(FLAG, str[i]))
		i++;
	return (i);
}

unsigned int	ft_width_format(const char *str)
{
	unsigned int	i;

	i = 0;
	if (str[i] == '*')
		i++;
	else
	{
		while (ft_isbase(DIGIT, str[i]))
			i++;
	}
	return (i);
}

unsigned int	ft_precision_format(const char *str)
{
	unsigned int	i;

	i = 0;
	if (str[i] == '.')
		i++;
	else
		return (0);
	if (str[i] == '*')
		i++;
	else
	{
		while (ft_isbase(DIGIT, str[i]))
			i++;
	}
	return (i);
}

int				ft_check_conversion_format(const char *str)
{
	str += ft_flag_format(str);
	str += ft_width_format(str);
	str += ft_precision_format(str);
	if (!ft_isbase(TYPE, *str))
		return (1);
	return (0);
}
