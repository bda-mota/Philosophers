/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:42:49 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/02 14:57:50 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (!parsing_input(&table, argv))
			return (EXIT_FAILURE);
		printf("number_of_philosphers: %d\n", table.number_of_philosphers);
		printf("time_to_die: %d\n", table.time_to_die);
		printf("time_to_eat: %d\n", table.time_to_eat);
		printf("time_to_sleep: %d\n", table.time_to_sleep);
		printf("number_of_meals: %d\n", table.number_of_meals);
	}
	else
	{
		printf("Error: invalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
