/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:27:27 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/30 18:44:29 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	get_int(t_mtx *mutex, int *value)
{
	int	ret;

	safe_mutex_handler(mutex, LOCK);
	ret = *value;
	safe_mutex_handler(mutex, UNLOCK);
	return (ret);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	safe_mutex_handler(mutex, LOCK);
	ret = *value;
	safe_mutex_handler(mutex, UNLOCK);
	return (ret);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	safe_mutex_handler(mutex, LOCK);
	ret = *value;
	safe_mutex_handler(mutex, UNLOCK);
	return (ret);
}

bool	is_simulation_over(t_table *table)
{
	return (get_bool(&table->death_mtx, &table->end));
}
