/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsulvac <fsulvac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:28:24 by fsulvac           #+#    #+#             */
/*   Updated: 2023/11/24 13:36:19 by fsulvac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_putnbr_hexa_helper(unsigned long long nb, const char *base)
{
	size_t	size;
	size_t	result;

	size = 16;
	result = 0;
	if (nb >= size)
	{
		result += ft_putnbr_hexa_helper(nb / size, base);
		result += write(1, &base[nb % size], 1);
	}
	else
	{
		result += write(1, &base[nb % size], 1);
	}
	return (result);
}

static int	ft_putnbr_hexa(unsigned int nbr)
{
	unsigned long long	nb;
	int					result;
	const char			*base = "0123456789abcdef";

	nb = (unsigned long long)nbr;
	result = 0;
	result += ft_putnbr_hexa_helper(nb, base);
	return (result);
}

int	print_hex_lowercase(unsigned int nbr)
{
	return (ft_putnbr_hexa(nbr));
}
