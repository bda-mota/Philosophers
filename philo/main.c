/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:42:49 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/04 08:40:58 by bda-mota         ###   ########.fr       */
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
