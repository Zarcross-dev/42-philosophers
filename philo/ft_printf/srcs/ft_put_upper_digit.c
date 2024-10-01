/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_upper_digit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:55:18 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/26 15:26:28 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_put_upper_digit(unsigned int n, unsigned int base, int *len)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= base)
		ft_put_upper_digit((n / base), base, len);
	*len += write(1, &hexa[n % base], 1);
}
