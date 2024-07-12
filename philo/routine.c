/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:52:18 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/12 14:48:06 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->table->number_of_philos == 1)
	{
		handle_one_philo(philo);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(philo->start);
		if (philo->table->all_read == 1)
		{
			pthread_mutex_unlock(philo->start);
			break ;
		}
		pthread_mutex_unlock(philo->start);
	}
	while (!death(philo))
	{
		philo_eat(philo);
		philo_sleep_n_think(philo);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	print_message(EAT, philo, philo->id);
	philo->eating = 1;
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;
	give_back_forks(philo);
}

void	philo_sleep_n_think(t_philo *philo)
{
	print_message(SLEEP, philo, philo->id);
	ft_usleep(philo->table->time_to_sleep);
	print_message(THINK, philo, philo->id);
}
