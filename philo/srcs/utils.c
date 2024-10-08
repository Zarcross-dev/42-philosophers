/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:25:01 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/07 16:46:19 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*safe_calloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(size, 1);
	if (!ptr)
	{
		printf("Malloc failed\n");
		exit(1);
	}
	return (ptr);
}