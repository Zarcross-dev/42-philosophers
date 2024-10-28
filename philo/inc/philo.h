/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 04:33:24 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/28 03:55:50 by beboccas         ###   ########.fr       */
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
# define DEBUG 1

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

typedef enum e_timecode
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}	t_timecode;

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DEAD
}	t_state;

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
	t_fork		*right_fork;
	t_fork		*left_fork;
	t_mtx		philo_mtx;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	long		nb_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nb_eat;
	long		start;
	bool		end;
	bool		all_threads_ready;
	long		nb_running_threads;
	pthread_t	monitor;
	t_fork		*forks;
	t_philo		*philos;
	t_mtx		table_mtx;
	t_mtx		print;
}				t_table;

int 		init(t_table *table, char **av);
int			valid_args(int ac, char **av);
int			is_num(char *str);
void		clean_exit(t_table *table);
int			free_structs(t_table *table);
void		wait_all_threads(t_table *table);
void		dinner_start(t_table *table);
void		*dinner_simulation(void *data);
void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo);
void		assign_forks(t_philo *philo, t_fork *fork, int pos);
void		print_status(t_philo *philo, t_state state, bool debug);
void		print_status_debug(t_philo *philo, t_state state);
void		*monitor_dinner(void *data);
bool		all_threads_ready(t_mtx *mtx, long *thrd, long *philo_nbr);
bool		philo_died(t_philo *philo);
void		*solo_philo(void *data);


/* Handlers */
void		safe_mutex_handler(t_mtx *mutex, t_opcode opcode);
void		safe_thread_handler(pthread_t *thread, void *(*f)(void *),
				void *data, t_opcode opcode);

void		handle_thread_error(int error);
void		handle_mutex_error(int error);

/* Utils*/
void		merror(t_table *table, char *str);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
void		*ft_calloc(size_t size, size_t nmemb);
void		ft_usleep(t_table *table, long ms);
void		*safe_calloc(size_t size);

/*Setters and Getters */
void		set_int(t_mtx *mutex, int *value, int new_value);
void		set_long(t_mtx *mutex, long *value, long new_value);
void		set_bool(t_mtx *mutex, bool *value, bool new_value);
int			get_int(t_mtx *mutex, int *value);
long		get_long(t_mtx *mutex, long *value);
bool		get_bool(t_mtx *mutex, bool *value);
long		get_time(t_timecode timecode);
bool		is_simulation_over(t_table *table);
void		increase_long(t_mtx *mutex, long *value, long increase);

#endif // PHILO_H
