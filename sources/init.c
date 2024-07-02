/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:25:27 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/02 17:25:44 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_init(t_table *table)
{
	table->ended = false;
	table->philos = malloc(sizeof(t_philo) * table->number_of_philos);
	if (!table->philos)
		return (print_error_number("malloc failed"));
	table->forks = malloc(sizeof(t_fork) * table->number_of_philos);
	if (!table->forks)
		return (print_error_number("malloc failed"));

}

void	handle_mutexes(int type)
{

}
