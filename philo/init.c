/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:42:03 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/04 11:44:03 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_the_dining_table(t_table *table, pthread_mutex_t *forks)
{
	table->dead_flag = 0;
	table->start_time = get_current_time();
	table->ended = false;
	table->all_born = false;
	handle_mutexes(table->write_lock, INIT);
	handle_mutexes(table->meal_lock, INIT);
	handle_mutexes(table->dead_lock, INIT);
	init_forks(&forks, table->number_of_philos);
}

void	init_forks(pthread_mutex_t *forks, int number_of_philos)
{
	int	i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * number_of_philos);
	if (!forks)
		return (print_error("malloc failed"));
	get_forks(forks);
	while (i < number_of_philos)
	{
		handle_mutexes(forks[i], INIT);
		i++;
	}
}

void	create_philos(t_philo *philos, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	philos = malloc(sizeof(t_philo) * table->number_of_philos);
	if (!philos)
		return (print_error("malloc failed"));
	while (i < table->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].dead = 0;
		philos[i].full = false;
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = get_current_time();
		philos[i].write_lock = &table->write_lock;
		philos[i].meal_lock = &table->meal_lock;
		philos[i].dead_lock = &table->dead_lock;
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[table->number_of_philos - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
