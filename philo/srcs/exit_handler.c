/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:35:03 by beboccas          #+#    #+#             */
/*   Updated: 2025/01/24 20:44:54 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	free_philo(t_table *table)
{
	int	i;
	
	i = -1;
	while (++i < table->nb_philo)
	{
		safe_mutex_handler(&table->philos[i].philo_mtx, DESTROY);
	}
	free(table->philos);
	return (1);
}

int	free_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		safe_mutex_handler(&table->forks[i].fork, DESTROY);
	}
	free(table->forks);
	return (1);
}

int	free_table(t_table *table)
{
	safe_mutex_handler(&table->table_mtx, DESTROY);
	safe_mutex_handler(&table->print, DESTROY);
	safe_mutex_handler(&table->death_mtx, DESTROY);
	safe_thread_handler(&table->monitor, NULL, NULL, DESTROY);
	free(table);
	return (1);
}

void	clean_exit(t_table *table)
{
	free_forks(table);
	free_philo(table);
	free_table(table);
	exit(1);
}
