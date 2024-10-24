/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:11:34 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/24 00:14:22 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	assign_forks(t_philo *philo, t_fork *fork, int pos)
{
	int	philo_nbr;
	
	philo_nbr = philo->table->nb_philo;
	if (philo->id % 2 == 0)
	{
		philo->right_fork = &fork[(pos + 1) % philo_nbr];
		philo->left_fork = &fork[pos];
	}
	else
	{
		philo->right_fork = &fork[pos];
		philo->left_fork = &fork[(pos + 1) % philo_nbr];
	}
}

int	init_philo(t_table *table)
{
	int		i;
	
	table->philos = ft_calloc(sizeof(t_philo) * table->nb_philo + 8, 1);
	if (!table->philos)
		return (0);
	i = 0;
	while (i < table->nb_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meal = 0;
		table->philos[i].full_of_spaghetti = false;
		table->philos[i].last_meal = 0;
		table->philos[i].table = table;
		safe_mutex_handler(&table->philos[i].philo_mtx, INIT);
		assign_forks(&table->philos[i], table->forks, i);
		i++;
		
	}
	return (1);
}

int	init_fork(t_table *table)
{
	int		i;
	
	table->forks = safe_calloc(sizeof(t_fork) * table->nb_philo);
	if (!table->forks)
		return (0);
	i = 0;
	while (i < table->nb_philo)
	{
		table->forks[i].id = i;
		safe_mutex_handler(&table->forks[i].fork, INIT);
		i++;
	}
	return (1);
}

int	init_table(t_table *table, char **av)
{
	table->nb_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->nb_eat = ft_atoi(av[5]);
	else
		table->nb_eat = -1;
	table->start = 0;
	table->end = false;
	table->all_threads_ready = false;
	safe_mutex_handler(&table->table_mtx, INIT);
	safe_mutex_handler(&table->print, INIT);
	return (1);
}

int init(t_table *table, char **av)
{
	if (!init_table(table, av))
		return (0);
	if (!init_fork(table))
		return (0);
	if (!init_philo(table))
		return (0);
	return (1);
}