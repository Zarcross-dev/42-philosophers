/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:20:24 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/14 12:00:54 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	if (a < b)
	{
		while (n > 0)
		{
			n--;
			b[n] = a[n];
		}
	}
	else if (a > b)
	{
		i = 0;
		while (i < n)
		{
			b[i] = a[i];
			i++;
		}
	}
	return (dest);
}
