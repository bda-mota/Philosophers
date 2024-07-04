/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:25:27 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/03 15:41:54 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_the_dining_table(t_table *table)
{
	int	i;

	i = 0;
	table->ended = false;
	table->all_born = false;
	handle_mutexes(table->table_mutex, INIT);
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
	philo->first_fork = &forks[(pos + 1) % philo->table->number_of_philos];
	philo->second_fork = &forks[pos];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[pos];
		philo->second_fork = &forks[(pos + 1) % philo->table->number_of_philos];
	}
}
