/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:35:03 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/29 16:02:12 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	free_philo(t_table *table)
{
	while (table->nb_philo)
	{
		table->nb_philo--;
		pthread_mutex_destroy(&table->philos[table->nb_philo].philo_mtx);
		free(table->philos[table->nb_philo].left_fork);
		free(table->philos[table->nb_philo].right_fork);
	}
	return (1);
}

int	free_forks(t_table *table)
{
	int	i;

	i = 0;
	while (table->forks[i].id != -1)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		i++;
	}
	return (1);
}

int	free_table(t_table *table)
{
	pthread_mutex_destroy(&table->table_mtx);
	pthread_mutex_destroy(&table->print);
	free(table->philos);
	free(table->forks);
	free(table);
	return (1);
}

void	clean_exit(t_table *table)
{
	free_forks(table);
	free_philo(table);
	free_table(table);
}
