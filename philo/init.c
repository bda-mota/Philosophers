/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:25:27 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/02 20:46:39 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_the_dining_table(t_table *table)
{
	int	i;

	i = 0;
	table->ended = false;
	table->philos = malloc(sizeof(t_philo) * table->number_of_philos);
	if (!table->philos)
		return (print_error_number("malloc failed"));
	table->forks = malloc(sizeof(t_fork) * table->number_of_philos);
	if (!table->forks)
		return (print_error_number("malloc failed"));
	while (i < table->number_of_philos)
	{
		handle_mutexes(table->forks[i].mutex, INIT);
		table->forks[i].id == i;
		i++;
	}
	give_birth_to_philos(table);
	return (EXIT_SUCCESS);
}

void	give_birth_to_philos(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->number_of_philos)
	{
		philo = &table->philos[i];
		philo->id = i + 1;
		philo->meals = 0;
		philo->full = false;
		philo->table = table;
		i++;
		take_forks(philo, table->forks);
	}
}

void	take_forks(t_philo *philo, t_fork *forks)
{
	int	pos;

	pos = philo->id - 1;
	philo->left_fork = &forks[(pos + 1) % philo->table->number_of_philos];
	philo->right_fork = &forks[pos];
	if (philo->id % 2 == 0)
	{
		philo->left_fork = &forks[pos];
		philo->right_fork = &forks[(pos + 1) % philo->table->number_of_philos];
	}
}

void	handle_mutexes(pthread_mutex_t mutex, int mode)
{
	if (mode == INIT)
		pthread_mutex_init(&mutex, NULL);
	else if (mode == LOCK)
		pthread_mutex_lock(&mutex);
	else if (mode == UNLOCK)
		pthread_mutex_unlock(&mutex);
	else if (mode == DESTROY)
		pthread_mutex_destroy(&mutex);
}

void	handle_threads(pthread_t thread, int mode)
{
	if (mode == CREATE)
		pthread_create(&thread, NULL, dinner, NULL);
	else if (mode == JOIN)
		pthread_join(&thread, NULL);
	else if (mode == DETACH)
		pthread_detach(&thread);
}

