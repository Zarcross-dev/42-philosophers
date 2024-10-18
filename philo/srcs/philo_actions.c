/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:50 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/18 16:09:04 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	go_to_sleep(t_philo *philo)
{
	print(philo, "is sleeping\n");
	usleep(philo->table->time_to_sleep * 1000);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	print(philo, "is eating\n");
	usleep(philo->table->time_to_eat * 1000);
	drop_forks(philo);
}