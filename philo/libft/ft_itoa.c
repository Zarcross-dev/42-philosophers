/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:23 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/16 18:46:10 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int	setneg(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	temp;
	int				neg;
	int				len;

	neg = isneg(n);
	temp = setneg(n);
	len = 0;
	while (++len, temp >= 10)
		temp /= 10;
	res = (char *)ft_calloc(len + 1 + neg, sizeof(char));
	if (!res)
		return (0);
	if (neg)
		res[0] = '-';
	temp = setneg(n);
	while (len-- > 0)
	{
		res[len + neg] = (temp % 10) + '0';
		temp /= 10;
	}
	return (res);
}
