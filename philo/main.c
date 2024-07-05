/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:42:49 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/05 13:20:30 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (argc == 5 || argc == 6)
	{
		if (!parsing_input(&table, argv))
			return (EXIT_FAILURE);
		philos = malloc(sizeof(t_philo) * table.number_of_philos);
		if (!philos)
			return (print_error_number("malloc failed"));
		forks = malloc(sizeof(pthread_mutex_t) * table.number_of_philos);
			if (!forks)
				return (print_error_number("malloc failed"));
		get_forks(forks);
		set_the_dining_table(&table, philos, forks);
		create_philos(philos, &table, forks);
		create_threads(philos, &table);
		dinners_end(philos, &table, NULL);
	}
	else
		return (print_error_number("incorrect number of arguments"));
	return (0);
}
