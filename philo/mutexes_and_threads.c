/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_and_threads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:59:51 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/03 15:07:20 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_mutexes(pthread_mutex_t mutex_id, int mode)
{
	if (mode == INIT)
		pthread_mutex_init(&mutex_id, NULL);
	else if (mode == LOCK)
		pthread_mutex_lock(&mutex_id);
	else if (mode == UNLOCK)
		pthread_mutex_unlock(&mutex_id);
	else if (mode == DESTROY)
		pthread_mutex_destroy(&mutex_id);
}

void	handle_mutexes_erros(int mode)
{
	if (mode == EINVAL)
		printf("Error: specified attributes are invalid\n");
	else if (mode == EDEADLK)
		printf("Error: a deadlock occurred\n");
	else if (mode == EBUSY)
		printf("Error: the mutex is blocked\n");
	else if (mode == EPERM)
		printf("Error: the mutex is not blocked by the calling thread\n");
	else if (mode == ENOMEM)
		printf("Error: there is not enough memory\n");
}

void	handle_threads(pthread_t thread_id, int mode)
{
	if (mode == CREATE)
		pthread_create(&thread_id, NULL, dinner, NULL);
	else if (mode == JOIN)
		pthread_join(&thread_id, NULL);
	else if (mode == DETACH)
		pthread_detach(&thread_id);
}

void	handle_threads_erros(int mode)
{
	if (mode == EINVAL)
		printf("Error: thread attributes are not valid\n");
	else if (mode == EAGAIN)
		printf("Error: there are no resources available to create"
			"another thread\n");
	else if (mode == EDEADLK)
		printf("Error: deadlock detected\n");
	else if (mode == ESRCH)
		printf("Error: there is no thread corresponding to the"
			"specified identifier\n");
	else if (mode == EPERM)
		printf("Error: the caller does not have permission to set"
			"the specified attributes\n");
}
