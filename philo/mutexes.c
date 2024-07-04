/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:53:29 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/04 11:45:09 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_mutexes(pthread_mutex_t mutex, t_mode mode)
{
	if (mode == INIT)
		handle_mutexes_error(pthread_mutex_init(&mutex, NULL), INIT);
	else if (mode == LOCK)
		handle_mutexes_error(pthread_mutex_lock(&mutex), LOCK);
	else if (mode == UNLOCK)
		handle_mutexes_error(pthread_mutex_unlock(&mutex), UNLOCK);
	else if (mode == DESTROY)
		handle_mutexes_error(pthread_mutex_destroy(&mutex), DESTROY);
}

void	handle_mutexes_error(int status, t_mode mode)
{
	if (status == 0)
		return ;
	else if (EINVAL == status && (mode == LOCK || mode == UNLOCK
			|| mode == DESTROY))
		printf("Error: mutex is invalid\n");
	else if (EINVAL == status && mode == INIT)
		printf("Error: specified attributes are invalid\n");
	else if (EDEADLK == status && mode == LOCK)
		printf("Error: deadlock detected\n");
	else if (EBUSY == status && (mode == DESTROY || mode == LOCK))
		printf("Error: mutex is locked\n");
	else if (ENOMEM == status && mode == INIT)
		printf("Error: insufficient memory\n");
	else if (EPERM == status)
		printf("Error: mutex is not blocked by the calling thread");
}

pthread_mutex_t	*get_forks(pthread_mutex_t *forks)
{
	static pthread_mutex_t	*new_forks;

	if (forks)
		new_forks = forks;
	return (new_forks);
}
