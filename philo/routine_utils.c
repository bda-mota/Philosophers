/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:16:46 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/11 20:13:30 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(FORK, philo, philo->id);
	ft_usleep(philo->table->time_to_die);
	pthread_mutex_unlock(philo->right_fork);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(FORK, philo, philo->id);
		pthread_mutex_lock(philo->right_fork);
		//print_message(FORK, philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(FORK, philo, philo->id);
		pthread_mutex_lock(philo->left_fork);
		//print_message(FORK, philo, philo->id);
	}
}

void	give_back_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}
