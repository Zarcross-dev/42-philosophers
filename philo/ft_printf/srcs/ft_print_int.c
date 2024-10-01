/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 02:56:01 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/22 02:56:01 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_print_int(int n)
{
	int	len;
	int	temp;

	temp = n;
	len = 0;
	if (n == -2147483648)
	{
		ft_putnbr_fd(n, 1);
		return (11);
	}
	if (n < 0)
	{
		len++;
		temp *= -1;
	}
	while (++len, temp >= 10)
		temp /= 10;
	ft_putnbr_fd(n, 1);
	return (len);
}
