/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_setup_army.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:35:59 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/13 16:13:00 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

void	ft_reset_datablock(t_data *data)
{
	free(data->flag);
	free(data->res);
	ft_init_datablock(data);
}

void	ft_init_datablock(t_data *data)
{
	data->flag = NULL;
	data->null_count = 0;
	data->type = 0;
	data->width = 0;
	data->w_val = 0;
	data->minus = 0;
	data->precision = 0;
	data->p_val = 0;
	data->zero = 0;
	data->no_flags = 0;
	data->res = NULL;
}
