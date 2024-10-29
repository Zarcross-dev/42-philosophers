/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:12:01 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/29 15:52:49 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	print_status_debug(t_philo *philo, t_state state)
{
	if (state == EATING && !philo->table->end)
		printf("%ld %d is eating \t\t [Meal: %ld]\n", get_time(MILLISECONDS)
			- philo->table->start, philo->id, philo->meal);
	else if (state == SLEEPING && !philo->table->end)
		printf("%ld %d is sleeping 💤\n", get_time(MILLISECONDS)
			- philo->table->start, philo->id);
	else if (state == THINKING && !philo->table->end)
		printf("%ld %d is thinking 💭\n", get_time(MILLISECONDS)
			- philo->table->start, philo->id);
	else if (state == TAKE_FIRST_FORK && !philo->table->end)
		printf("%ld %d has taken a fork \t\t [Fork: %d]\n",
			get_time(MILLISECONDS) - philo->table->start,
			philo->id, philo->left_fork->id);
	else if (state == TAKE_SECOND_FORK && !philo->table->end)
		printf("%ld %d has taken a fork \t\t [Fork: %d]\n",
			get_time(MILLISECONDS) - philo->table->start,
			philo->id, philo->right_fork->id);
	else if (state == DEAD)
		printf("%ld %d died \t\t\t [Bro just died lmao]\n",
			get_time(MILLISECONDS) - philo->table->start, philo->id);
}

void	print_status(t_philo *philo, t_state state, bool debug)
{
	if (debug)
		print_status_debug(philo, state);
	else if (state == EATING && !philo->table->end)
		printf("%ld %d is eating\n", get_time(MILLISECONDS)
			- philo->table->start, philo->id);
	else if (state == SLEEPING && !philo->table->end)
		printf("%ld %d is sleeping\n", get_time(MILLISECONDS)
			- philo->table->start, philo->id);
	else if (state == THINKING && !philo->table->end)
		printf("%ld %d is thinking\n", get_time(MILLISECONDS)
			- philo->table->start, philo->id);
	else if (state == TAKE_FIRST_FORK && !philo->table->end)
		printf("%ld %d has taken a fork\n", get_time(MILLISECONDS)
			- philo->table->start, philo->id);
	else if (state == TAKE_SECOND_FORK && !philo->table->end)
		printf("%ld %d has taken a fork\n", get_time(MILLISECONDS)
			- philo->table->start, philo->id);
	else if (state == DEAD)
		printf("%ld %d died\n", get_time(MILLISECONDS)
			- philo->table->start, philo->id);
}
