/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 02:56:07 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/22 02:56:07 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdint.h>

void	ft_print_pointer(size_t ptr, int *len)
{
	char	str[25];
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (ptr == 0)
	{
		(*len) += ft_putchar('0', 1);
		return ;
	}
	while (ptr != 0)
	{
		str[i] = hex[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
	{
		(*len) += ft_putchar(str[i], 1);
	}
}
