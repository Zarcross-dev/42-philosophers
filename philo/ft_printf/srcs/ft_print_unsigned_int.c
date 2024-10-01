/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 02:56:17 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/22 02:56:17 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_print_unsigned_int(unsigned int n)
{
	int	len;

	if (n >= 10)
	{
		len = ft_print_unsigned_int(n / 10);
		len += ft_print_unsigned_int(n % 10);
	}
	else
	{
		ft_putchar((n + '0'), 1);
		return (1);
	}
	return (len);
}
