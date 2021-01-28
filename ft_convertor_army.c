/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_army.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:28:19 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/15 16:24:51 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

void	ft_convert_base(unsigned int nbr, char *s,
						char *base, unsigned int size)
{
	unsigned int b_len;
	unsigned int tmp_nbr;

	b_len = ft_strlen(base);
	while (nbr >= b_len)
	{
		tmp_nbr = nbr % b_len;
		s[size] = base[tmp_nbr];
		nbr = nbr / b_len;
		size--;
	}
	s[size] = base[nbr];
	size--;
	if (size == 0)
		s[size] = '-';
}

void	ft_convert_address_base(unsigned long nbr,
									char *s, char *base, unsigned int size)
{
	unsigned int	b_len;
	unsigned long	tmp_nbr;

	b_len = ft_strlen(base);
	while (nbr > 0)
	{
		tmp_nbr = nbr % b_len;
		s[size] = base[tmp_nbr];
		nbr = nbr / b_len;
		size--;
	}
	s[size] = 'x';
	size--;
	s[size] = '0';
}
