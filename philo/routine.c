/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:52:18 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/08 16:54:20 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!death(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

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

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork 🍴", philo, philo->id);
	if (philo->table->number_of_philos == 1)
	{
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->own_fork);
	print_message("has taken a fork 🍴", philo, philo->id);
	philo->eating = 1;
	print_message(ORANGE"is eating 🍝"RESET, philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->table->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->own_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_message(CYAN"is sleeping 💤"RESET, philo, philo->id);
	ft_usleep(philo->table->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_message(GREEN"is thinking 💭"RESET, philo, philo->id);
}
