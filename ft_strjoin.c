/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adconsta <adconsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 21:02:44 by adconsta          #+#    #+#             */
/*   Updated: 2020/12/13 13:26:14 by adconsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l1 + l2 + 1));
	if (str == NULL)
		return (NULL);
	ft_memmove(str, s1, l1);
	ft_memmove(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	return (str);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned	char	*d;
	unsigned	char	*s;

	if (!dest && !src)
		return (dest);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
		d = ft_memcpy(dest, src, n);
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned	char			*dest2;
	const	unsigned	char	*src2;

	if (!src && !dest)
		return (dest);
	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	while (n > 0)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
		n--;
	}
	return (dest);
}
