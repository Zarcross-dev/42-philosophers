/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_summon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:49:07 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/11 16:20:51 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_life(t_philo *philo)
{
	while (1)
	{
		eat(philo);
		go_to_sleep(philo);
		printf("Philo %d is thinking\n", philo->id);
	}
}

void	summon_philos(t_table *table)
{
	int	i;

	i = 0;
	table->philo = safe_calloc(sizeof(t_philo) * table->data->nb_philo);
	while (i < table->data->nb_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].last_meal = 0;
		table->philo[i].data = table->data;
		table->philo[i].left_fork = &table->forks[i];
		table->philo[i].right_fork = &table->forks[(i + 1) % table->data->nb_philo];
		pthread_create(&table->philo[i].thread, NULL, (void *) philo_life, &table->philo[i]);
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < table->data->nb_philo)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
}