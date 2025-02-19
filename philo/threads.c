/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:24:32 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/12 17:44:52 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *philos, t_table *table)
{
	pthread_t	waiter;
	int			i;

	i = 0;
	if (pthread_create(&waiter, NULL, &monitor, table->philos) != 0)
		dinners_end(philos, table, "pthread_create failed");
	while (i < table->number_of_philos)
	{
		if (pthread_create(&philos[i].thread_id, NULL, &routine,
				&philos[i]) != 0)
			dinners_end(philos, table, "pthread_create failed");
		i++;
	}
	pthread_mutex_lock(&table->start);
	table->all_read = 1;
	pthread_mutex_unlock(&table->start);
	if (pthread_join(waiter, NULL) != 0)
		dinners_end(philos, table, "pthread_join failed");
	i = 0;
	while (i < table->number_of_philos)
	{
		if (pthread_join(philos[i].thread_id, NULL) != 0)
			dinners_end(philos, table, "pthread_join failed");
		i++;
	}
}

int	dinners_end(t_philo *philos, t_table *table, const char *error)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = get_forks(NULL);
	while (i < table->number_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->dead_lock);
	free(philos);
	if (error)
		print_error_number(error);
	return (EXIT_FAILURE);
}
