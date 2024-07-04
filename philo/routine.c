/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:52:18 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/04 13:55:00 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	while (1)
	{
		if (philo->dead)
			break ;
		eat(philo);
		sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	*monitor(t_table *table)
{
	while (1)
	{
		if (table->dead_flag == 1)
			break ;
		if (table->ended)
			break ;
		if (table->number_of_meals != -1)
			if (table->number_of_meals == table->number_of_philos)
				break ;
	}
	return (NULL);
}

void	sleep(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_message("is thinking", philo);
	ft_usleep(500);
}

void	eat(t_philo *philos)
{
	pthread_mutex_lock(philos->write_lock);
	printf("%ld %d has taken a fork \n", get_current_time(), philos->id);
	pthread_mutex_unlock(philos->write_lock);
	if (philos->table->number_of_philos == 1)
	{
		printf("%ld %d has died\n", get_current_time(), philos->id);
		philos->dead = true;
		return ;
	}
	printf("%ld %d has taken a fork \n", get_current_time(), philos->id);
	philos->meals_eaten++;
	if (philos->meals_eaten == philos->table->number_of_meals)
		philos->full = true;
	philos->last_meal_time = get_current_time();
	pthread_mutex_lock(philos->meal_lock);
	printf("%ld %d is eating\n", get_current_time(), philos->id);
	pthread_mutex_unlock(philos->meal_lock);
}
