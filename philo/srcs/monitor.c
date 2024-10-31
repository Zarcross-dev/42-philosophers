/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:46:17 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/31 17:54:00 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	cclock(t_table *table)
{
	long	time;

	time = get_time(MILLISECONDS);
	printf("Time: %ld\n", time - table->start);
	ft_usleep(table, 1);
}

void	*monitor_dinner(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!all_threads_ready(&table->table_mtx, &table->nb_running_threads,
			&table->nb_philo))
		;
	while (!is_simulation_over(table))
	{
		i = -1;
		while (++i < table->nb_philo && !is_simulation_over(table))
		{
			cclock(table);
			if (philo_died(table->philos + i))
			{
				set_bool(&table->table_mtx, &table->end, true);
				print_status(table->philos + i, DEAD, DEBUG);
			}
		}
		ft_usleep(table, 1);
	}
	return (NULL);
}
