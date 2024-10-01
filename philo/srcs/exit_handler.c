/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:35:03 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/01 16:52:34 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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