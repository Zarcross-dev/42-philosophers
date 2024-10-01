/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarcross <zarcross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:55:18 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/26 17:58:57 by zarcross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_put_digit(unsigned int n, unsigned int base, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= base)
	{
		ft_put_digit((n / base), base, len);
	}
	*len += write(1, &hexa[n % base], 1);
}
