/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:59:53 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/22 02:05:57 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	dinner_start(t_table *table)
{
	int i;

	i = 0;
	if (table->nb_eat == 0)
		return ;
	else if (table->nb_eat == 1)
		//todo
	else
		while (i++ <= table->nb_philo)
			safe_thread_handler(&table->philos[i].thread, dinner_simulation, 
				&table->philos[i], CREATE);
}