/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:49:16 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/01 16:52:58 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	free_structs(t_table *table)
{
	if (table->data)
		free(table->data);
	if (table->philo)
		free(table->philo);
	if (table)
		free(table);
	return (1);
}