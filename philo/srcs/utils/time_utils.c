/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 02:44:01 by beboccas          #+#    #+#             */
/*   Updated: 2024/12/16 10:14:57 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

long	get_time(t_timecode timecode)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	if (timecode == SECONDS)
		return (tv.tv_sec + tv.tv_usec / 1000000);
	else if (timecode == MILLISECONDS)
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	else if (timecode == MICROSECONDS)
		return (tv.tv_sec * 1000000 + tv.tv_usec);
	else
		return (0);
	return (0);
}

void	ft_usleep(t_table *table, long ms)
{
	long	start_time;
	long	remaning_time;
	long	elapsed_time;

	start_time = get_time(MILLISECONDS);
	while (get_time(MILLISECONDS) - start_time < ms)
	{
		if (is_simulation_over(table))
			break ;
		elapsed_time = get_time(MILLISECONDS) - start_time;
		remaning_time = ms - elapsed_time;
		if (remaning_time > 100)
			usleep(remaning_time / 10);
		else
		{
			while (get_time(MILLISECONDS) - start_time < ms)
				;
		}
	}
}
