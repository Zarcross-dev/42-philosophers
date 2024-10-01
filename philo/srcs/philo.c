/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 04:27:01 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/01 16:54:20 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int valid_args(int ac, char **av)
{
	int i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (0);
	while (i < ac)
	{
		if (!is_num(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if(!valid_args(ac, av))
	{
		printf("Invalid arguments\n");
		return (1);
	}
	table = safe_calloc(sizeof(t_table));
	if(!init(table, av))
		clean_exit(table);
	return (1);
}
