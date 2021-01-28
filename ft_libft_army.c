/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_army.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:36:35 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/15 16:16:50 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

unsigned int	ft_strlen(char const *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void			ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int				ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int				ft_atoi(const char *str)
{
	int				sign;
	int				nbr;
	unsigned int	i;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
