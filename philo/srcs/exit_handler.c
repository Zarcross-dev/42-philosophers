/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:35:03 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/29 16:14:13 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	free_philo(t_table *table)
{
	(void)table;
	return (1);
}

int	free_forks(t_table *table)
{
	(void)table;
	return (1);
}

int	free_table(t_table *table)
{
	(void)table;
	return (1);
}

void	clean_exit(t_table *table)
{
	free_forks(table);
	free_philo(table);
	free_table(table);
}
