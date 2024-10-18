/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 04:33:24 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/18 17:21:44 by beboccas         ###   ########.fr       */
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
# include <stdbool.h>
# include <errno.h>

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx 	fork;
	int		id;
}			t_fork;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	long		meal;
	bool 		full_of_spaghetti;
	long		last_meal;
	t_fork		*left_fork;
	t_fork		*right_fork;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_eat;
	int			start;
	bool		end;
	t_fork		*forks;
	t_philo		*philos;
	t_mtx		print;
}				t_table;

void		*safe_calloc(size_t size);
int 		init(t_table *table, char **av);
int			valid_args(int ac, char **av);
int			is_num(char *str);
void		clean_exit(t_table *table);
int			free_structs(t_table *table);
void		merror(t_table *table, char *str);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t size, size_t nmemb);
void		summon_philos(t_table *table);
void		philo_life(t_philo *philo);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		go_to_sleep(t_philo *philo);
void		eat(t_philo *philo);
long long	timestamp(void);
void		ft_usleep(int ms);
void		print(t_philo *philo, char *str);
void		safe_mutex_handler(t_mtx *mutex, t_opcode opcode);
void		safe_thread_handler(pthread_t *thread, void *(*f)(void *),
				void *data, t_opcode opcode);
void		handle_thread_error(int error);
void		handle_mutex_error(int error);

#endif // PHILO_H
