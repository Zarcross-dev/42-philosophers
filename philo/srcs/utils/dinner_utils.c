/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:50 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/28 03:11:00 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

bool	philo_died(t_philo *philo)
{
	if (get_bool(&philo->philo_mtx, &philo->full_of_spaghetti))
		return (false);
	if (get_time(MILLISECONDS) - get_long(&philo->philo_mtx, &philo->last_meal) > philo->table->time_to_die)
		return (true);
	return (false);
}

void	philo_eat(t_philo *philo)
{
	safe_mutex_handler(&philo->right_fork->fork, LOCK);
	print_status(philo, TAKE_FIRST_FORK, DEBUG);
	safe_mutex_handler(&philo->left_fork->fork, LOCK);
	print_status(philo, TAKE_SECOND_FORK, DEBUG);
	set_long(&philo->philo_mtx, &philo->last_meal, get_time(MILLISECONDS));
	philo->meal++;
	print_status(philo, EATING, DEBUG);
	ft_usleep(philo->table, philo->table->time_to_eat);
	if(philo->table->nb_eat > 0 && philo->meal == philo->table->nb_eat)
		set_bool(&philo->philo_mtx, &philo->full_of_spaghetti, true);
	safe_mutex_handler(&philo->right_fork->fork, UNLOCK);
	safe_mutex_handler(&philo->left_fork->fork, UNLOCK);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, THINKING, DEBUG);
}