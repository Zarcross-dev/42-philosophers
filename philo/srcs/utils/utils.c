/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:12:01 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/24 00:29:08 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	print_status_debug(t_philo *philo, t_state state)
{
	if (state == EATING)
		printf("%ld %d is eating [meal : %ld]\n", get_time(MILLISECONDS) - philo->table->start, philo->id, philo->meal);
	else if (state == SLEEPING)
		printf("%ld %d is sleeping\n", get_time(MILLISECONDS) - philo->table->start, philo->id);
	else if (state == THINKING)
		printf("%ld %d is thinking\n", get_time(MILLISECONDS) - philo->table->start, philo->id);
	else if (state == TAKE_FIRST_FORK)
		printf("%ld %d has taken fork %d\n", get_time(MILLISECONDS) - philo->table->start, philo->id, philo->left_fork->id);
	else if (state == TAKE_SECOND_FORK)
		printf("%ld %d has taken fork %d\n", get_time(MILLISECONDS) - philo->table->start, philo->id, philo->right_fork->id);
	else if (state == DEAD)
		printf("%ld %d died\n", get_time(MILLISECONDS) - philo->table->start, philo->id);
}

void	print_status(t_philo *philo, t_state state, bool debug)
{
	if (debug)
		print_status_debug(philo, state);
	else if (state == EATING)
		printf("%ld %d is eating\n", get_time(MILLISECONDS) - philo->table->start, philo->id);
	else if (state == SLEEPING)
		printf("%ld %d is sleeping\n", get_time(MILLISECONDS) - philo->table->start, philo->id);
	else if (state == THINKING)
		printf("%ld %d is thinking\n", get_time(MILLISECONDS) - philo->table->start, philo->id);
	else if (state == TAKE_FIRST_FORK)
		printf("%ld %d has taken a fork\n", get_time(MILLISECONDS) - philo->table->start, philo->id);
	else if (state == TAKE_SECOND_FORK)
		printf("%ld %d has taken a fork\n", get_time(MILLISECONDS) - philo->table->start, philo->id);
	else if (state == DEAD)
		printf("%ld %d died\n", get_time(MILLISECONDS) - philo->table->start, philo->id);	
}