/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:42:03 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/11 11:09:19 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_the_dining_table(t_table *table, t_philo *philos,
		pthread_mutex_t *forks)
{
	table->dead_flag = 0;
	table->philos = philos;
	table->all_read = 0;
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	init_forks(forks, table->number_of_philos);
}

void	init_forks(pthread_mutex_t *forks, int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	create_philos(t_philo *philos, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < table->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].dead = &table->dead_flag;
		philos[i].start_at = get_current_time();
		philos[i].last_meal_time = get_current_time();
		philos[i].write_lock = &table->write_lock;
		philos[i].meal_lock = &table->meal_lock;
		philos[i].dead_lock = &table->dead_lock;
		philos[i].table = table;
		philos[i].own_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[table->number_of_philos - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}
