/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:38:47 by beboccas          #+#    #+#             */
/*   Updated: 2024/10/29 15:53:06 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	handle_mutex_error(int error)
{
	if (error == EBUSY)
		printf("The mutex is already locked.\n");
	else if (error == EINVAL)
		printf("The value specified by mutex does not refer to an \
			initialized mutex.\n");
	else if (error == EAGAIN)
		printf("The mutex could not be acquired because the maximum \
			number of recursive locks for mutex has been exceeded.\n");
	else if (error == EDEADLK)
		printf("A deadlock condition was detected or the current thread \
			already owns the mutex.\n");
}

void	safe_mutex_handler(t_mtx *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
}

void	handle_thread_error(int error)
{
	if (error == EAGAIN)
		printf("No necessary resources to create another thread\n");
	else if (error == EINVAL)
		printf("Invalid settings in attr.\n");
	else if (error == EPERM)
		printf("No permission to set the scheduling policy and \
			parameters specified in attr.\n");
}

void	safe_thread_handler(pthread_t *thread, void *(*f)(void *),
		void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		handle_thread_error(pthread_create(thread, NULL, f, data));
	else if (opcode == JOIN)
		handle_thread_error(pthread_join(*thread, NULL));
	else if (opcode == DETACH)
		handle_thread_error(pthread_detach(*thread));
}
