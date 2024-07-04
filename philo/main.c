/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:42:49 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/03 15:12:37 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (!parsing_input(&table, argv))
			return (EXIT_FAILURE);
		set_the_dining_table(&table);
		dinner_start(&table);
	}
	else
		return (print_error_number("incorrect number of arguments"));
	return (0);
}

void	*dinner(void)
{
	printf("thread created\n");
}
	// printf("number_of_philosphers: %d\n", table.number_of_philosphers);
	// printf("time_to_die: %d\n", table.time_to_die);
	// printf("time_to_eat: %d\n", table.time_to_eat);
	// printf("time_to_sleep: %d\n", table.time_to_sleep);
	// printf("number_of_meals: %d\n", table.number_of_meals);
