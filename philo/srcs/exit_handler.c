/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:35:03 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/09 16:33:38 by beboccas         ###   ########.fr       */
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

void	clean_exit(t_table *table)
{
	free_structs(table);
	exit(1);
}

void	merror(t_table *table, char *str)
{
	free_structs(table);
	printf("%s\n", str);
	exit(1);
}