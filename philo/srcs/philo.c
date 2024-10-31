/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 04:27:01 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/31 21:13:26 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	caca_liquide()
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static void	dodo(long ms)
{
	long	start_time;
	long	remaning_time;
	long	elapsed_time;

	start_time = caca_liquide();
	while (caca_liquide() - start_time < ms)
	{
		elapsed_time = caca_liquide() - start_time;
		remaning_time = ms - elapsed_time;
		if (remaning_time > 100)
			usleep(remaning_time / 10);
		else
		{
			while (caca_liquide() - start_time < ms)
				;
		}
	}
}

void	tictic(long t)
{
	long	time;
	(void)t;
	time = caca_liquide();
	printf("Time: %ld\n", time);
	dodo(1);
}

int	valid_args(int ac, char **av)
{
	int	i;

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

	if (!valid_args(ac, av))
	{
		printf("Invalid arguments\n");
		return (1);
	}
	/*table = safe_calloc(sizeof(t_table));
	if (!init(table, av))
		clean_exit(table);
	dinner_start(table);
	clean_exit(table);
	return (1);*/
	table = safe_calloc(sizeof(t_table));
	table->start = caca_liquide();
	printf("Start: %ld\n", caca_liquide());
	while (1)
	{
		tictic(table->start);
	}
}
