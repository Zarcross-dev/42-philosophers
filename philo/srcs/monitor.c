/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:46:17 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/28 03:49:58 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*monitor_dinner(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	
	while (!all_threads_ready(&table->table_mtx, &table->nb_running_threads, &table->nb_philo))
		;

	while (!is_simulation_over(table))
	{
		i = -1;
		while (++i < table->nb_philo && !is_simulation_over(table))
		{
			if (philo_died(table->philos + i))
			{
				set_bool(&table->table_mtx, &table->end, true);
				print_status(table->philos + i, DEAD, DEBUG);
			}
		}
	}
	return (NULL);
}