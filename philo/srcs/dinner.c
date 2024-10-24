/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:59:53 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/24 00:20:34 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*dinner_simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);

	while (!is_simulation_over(philo->table))
	{
		if (philo->full_of_spaghetti)
			break ;
		philo_eat(philo);
		print_status(philo, SLEEPING, DEBUG);
		ft_usleep(philo->table, philo->table->time_to_sleep);
		philo_think(philo);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int i;

	i = -1;
	if (table->nb_eat == 0)
		return ;
	else if (table->nb_eat == 1)
		{}
	else
	{
		while (++i <= table->nb_philo)
			safe_thread_handler(&table->philos[i].thread, dinner_simulation, 
				&table->philos[i], CREATE);
	}

	table->start = get_time(MILLISECONDS);
	set_bool(&table->table_mtx, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->nb_philo)
		safe_thread_handler(&table->philos[i].thread, NULL, NULL, JOIN);

	
}