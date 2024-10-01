/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:25:07 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/14 13:27:53 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mlc;

	mlc = malloc(nmemb * size);
	if (!mlc)
		return (0);
	else
		ft_memset(mlc, 0, nmemb * size);
	return (mlc);
}
