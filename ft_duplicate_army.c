/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_army.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:22:19 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/13 17:30:33 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

char	*ft_chardup(int c)
{
	char *tmp;

	tmp = malloc(sizeof(char) * 2);
	if (tmp == NULL)
		return (tmp);
	tmp[0] = (char)c;
	tmp[1] = '\0';
	return (tmp);
}

char	*ft_strdup(char *str)
{
	char		*tmp;
	size_t		i;

	if (str == NULL)
		return (ft_strdup("(null)"));
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_u_itoa_base_dup(unsigned int nbr, char *base)
{
	unsigned int	size;
	unsigned int	b_len;
	unsigned int	tmp_nbr;
	char			*str;

	size = 1;
	tmp_nbr = nbr;
	b_len = (unsigned int)ft_strlen(base);
	while (nbr >= b_len)
	{
		size++;
		nbr = nbr / b_len;
	}
	nbr = tmp_nbr;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	ft_convert_base(nbr, str, base, --size);
	return (str);
}

char	*ft_itoa_base_dup(int n, char *base)
{
	unsigned int	nbr;
	unsigned int	size;
	unsigned int	b_len;
	char			*str;

	nbr = (n < 0 ? -n : n);
	size = (n < 0 ? 2 : 1);
	b_len = ft_strlen(base);
	while (nbr >= b_len)
	{
		size++;
		nbr = nbr / b_len;
	}
	nbr = (n < 0 ? -n : n);
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	ft_convert_base(nbr, str, base, --size);
	return (str);
}

char	*ft_address_dup(void *ptr, char *base, t_data data)
{
	unsigned int	size;
	unsigned long	nbr;
	unsigned int	b_len;
	char			*str;

	if (ptr == NULL && data.precision == 0)
		return (ft_strdup("0x0"));
	else if (ptr == NULL && data.precision && data.p_val == 0)
		return (ft_strdup("0x"));
	size = 2;
	nbr = (unsigned long)ptr;
	b_len = ft_strlen(base);
	while (nbr > 0)
	{
		size++;
		nbr = nbr / b_len;
	}
	nbr = (unsigned long)ptr;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	ft_convert_address_base(nbr, str, base, --size);
	return (str);
}
