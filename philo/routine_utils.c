/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:16:46 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/19 14:15:20 by bda-mota         ###   ########.fr       */
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

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_message("has taken a fork 🍴", philo, philo->id);
		pthread_mutex_lock(philo->own_fork);
		print_message("has taken a fork 🍴", philo, philo->id);
	}
	else
	{
		usleep(40);
		pthread_mutex_lock(philo->own_fork);
		print_message("has taken a fork 🍴", philo, philo->id);
		pthread_mutex_lock(philo->right_fork);
		print_message("has taken a fork 🍴", philo, philo->id);
	}
}

void	give_back_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->own_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->own_fork);
	}
}
