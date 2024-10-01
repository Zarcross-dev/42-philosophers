/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:20:30 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/14 12:00:22 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	size_t	i;

	a = (char)c;
	i = ft_strlen(s);
	if (a == '\0')
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == a)
			return ((char *)s + i);
	}
	return (NULL);
}
