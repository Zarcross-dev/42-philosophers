/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:20:26 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/14 12:00:39 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*b;

	a = c;
	b = (char *)s;
	while (*b)
	{
		if (*b == a)
			return (b);
		b++;
	}
	if (!a)
		return (b);
	return (NULL);
}
