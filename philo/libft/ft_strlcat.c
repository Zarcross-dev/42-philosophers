/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 06:07:57 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/14 12:00:34 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (dest[i] && i < size)
		i++;
	if (i < size)
	{
		j = 0;
		while (src[j] && i + j + 1 < size)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	dest_len = i;
	while (src[src_len])
		src_len++;
	return (dest_len + src_len);
}
/*
#include <stdio.h>
int    main()
{
	char dest[11] = 'a';
    write(1, "\n", 1);
    write(1, dest, 15);
    printf("Result : %d", ft_strlcat(dest, "lorem", 15));
}
*/