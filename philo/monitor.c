/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:33:14 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/05 12:54:13 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *ptr)
{
	t_table	*table;

	table = (t_table *)ptr;
	while (1)
	{
		if (cardiac_monitor(table->philos) == 1
			|| waiter_check(table->philos) == 1)
			break ;
	}
	return (ptr);
}

int	cardiac_monitor(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->table->number_of_philos)
	{
		if (cardiac_monitor_aux(&philos[i]))
		{
			pthread_mutex_lock(philos[i].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[i].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	cardiac_monitor_aux(t_philo *philo)
{
	size_t	time;

	time = get_current_time() - philo->last_meal_time;
	pthread_mutex_lock(philo->meal_lock);
	if (time >= philo->table->time_to_die && philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	waiter_check(t_philo *philos)
{
	int		i;
	int		satisfied;

	i = 0;
	satisfied = 0;
	if (philos->table->number_of_meals == -1)
		return (0);
	while (i < philos->table->number_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos->table->number_of_meals)
			satisfied++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (satisfied == philos->table->number_of_meals)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}
