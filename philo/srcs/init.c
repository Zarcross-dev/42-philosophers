/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:11:34 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/01 16:55:42 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_table(t_table *table, char **av)
{
	table->data = safe_calloc(sizeof(t_data));
	table->data->nb_philo = ft_atoi(av[1]);
	table->data->time_to_die = ft_atoi(av[2]);
	table->data->time_to_eat = ft_atoi(av[3]);
	table->data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->data->nb_eat = ft_atoi(av[5]);
	else
		table->data->nb_eat = -1;
	table->philo = NULL;
	table->forks = NULL;
	pthread_mutex_init(&table->mutex, NULL);
	return (1);
}

int init(t_table *table, char **av)
{
	if (!init_table(table, av))
		return (0);
	return (1);
}