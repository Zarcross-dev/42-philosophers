/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:50 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/11 16:16:53 by beboccas         ###   ########.fr       */
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
	printf("Philo %d is sleeping\n", philo->id);
	usleep(philo->data->time_to_sleep * 1000);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	printf("Philo %d is eating\n", philo->id);
	usleep(philo->data->time_to_eat * 1000);
}