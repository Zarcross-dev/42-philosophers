/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:59:53 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/28 03:47:56 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*solo_philo(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mtx, &philo->last_meal, get_time(MILLISECONDS));
	increase_long(&philo->table->table_mtx, &philo->table->nb_running_threads, 1);
	print_status(philo, TAKE_FIRST_FORK, DEBUG);
	while (!is_simulation_over(philo->table))
		ft_usleep(philo->table, 200);
	return (NULL);
}

void	*dinner_simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mtx, &philo->last_meal, get_time(MILLISECONDS));
	increase_long(&philo->table->table_mtx, &philo->table->nb_running_threads, 1);
	while (!is_simulation_over(philo->table))
	{
		printf("ici\n");
		if (philo->full_of_spaghetti)
			break ;
		philo_think(philo);
		philo_eat(philo);
		print_status(philo, SLEEPING, DEBUG);
		ft_usleep(philo->table, philo->table->time_to_sleep);
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
		safe_thread_handler(&table->philos[0].thread, solo_philo, &table->philos[0], CREATE);
	else
	{
		while (++i < table->nb_philo)
			safe_thread_handler(&table->philos[i].thread, dinner_simulation, 
				&table->philos[i], CREATE);
	}
	safe_thread_handler(&table->monitor, monitor_dinner, table, CREATE);
	table->start = get_time(MILLISECONDS);
	set_bool(&table->table_mtx, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->nb_philo)
		safe_thread_handler(&table->philos[i].thread, NULL, NULL, JOIN);
}