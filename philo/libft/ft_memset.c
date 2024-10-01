/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:03:00 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/14 12:00:52 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*u;

	u = (unsigned char *)b;
	while (n > 0)
	{
		*u = (char) c;
		u++;
		n--;
	}
	return (b);
}
