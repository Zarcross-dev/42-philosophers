/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:33:55 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/23 19:37:23 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	set_int(t_mtx *mutex, int *value, int new_value)
{
	safe_mutex_handler(mutex, LOCK);
	*value = new_value;
	safe_mutex_handler(mutex, UNLOCK);
}

void	set_long(t_mtx *mutex, long *value, long new_value)
{
	safe_mutex_handler(mutex, LOCK);
	*value = new_value;
	safe_mutex_handler(mutex, UNLOCK);
}

void	set_bool(t_mtx *mutex, bool *value, bool new_value)
{
	safe_mutex_handler(mutex, LOCK);
	*value = new_value;
	safe_mutex_handler(mutex, UNLOCK);
}
