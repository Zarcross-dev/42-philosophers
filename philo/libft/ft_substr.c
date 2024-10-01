/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarcross <zarcross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:36 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/16 23:51:58 by zarcross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	l;

	l = ft_strlen(s);
	if (start + len > l)
		len = l - start;
	if (start >= l)
		return ((char *)ft_calloc(1, sizeof(char)));
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	ft_memcpy(res, s + start, len);
	return (res);
}
