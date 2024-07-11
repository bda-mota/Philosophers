/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:52:18 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/11 20:13:43 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
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
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	if (philo->table->number_of_philos == 1)
	{
		handle_one_philo(philo);
		return ;
	}
	take_forks(philo);
	philo->eating = 1;
	print_message(FORK, philo, philo->id);
	print_message(EAT, philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;
	give_back_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	print_message(SLEEP, philo, philo->id);
	ft_usleep(philo->table->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_message(THINK, philo, philo->id);
}

