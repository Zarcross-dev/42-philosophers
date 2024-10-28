/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:40:07 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/28 03:29:22 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mtx, &table->all_threads_ready))
		;
}

bool	all_threads_ready(t_mtx *mtx, long *thrd, long *philo_nbr)
{
	bool	ret;

	ret = false;
	safe_mutex_handler(mtx, LOCK);
	if (*thrd == *philo_nbr)
		ret = true;
	safe_mutex_handler(mtx, UNLOCK);
	return (ret);
}

void	increase_long(t_mtx *mutex, long *value, long increase)
{
	safe_mutex_handler(mutex, LOCK);
	(*value) += increase;
	safe_mutex_handler(mutex, UNLOCK);
}