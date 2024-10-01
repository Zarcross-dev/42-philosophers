/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 04:33:24 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/01 16:54:25 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "../ft_printf/headers/ft_printf.h"

typedef struct s_data
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_eat;
}			t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct s_table
{
	t_data		*data;
	t_philo		*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
}				t_table;

void	*safe_calloc(size_t size);
int 	init(t_table *table, char **av);
int		valid_args(int ac, char **av);
int		is_num(char *str);
void	clean_exit(t_table *table);
int		free_structs(t_table *table);
void	merror(t_table *table, char *str);


#endif // PHILO_H
