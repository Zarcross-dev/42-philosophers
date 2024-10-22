/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:12:01 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/22 03:12:05 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d %s", timestamp() - philo->table->start, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);
}