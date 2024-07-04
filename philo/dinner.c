/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:08:46 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/03 15:57:09 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dinner_start(t_table *table)
{
	int	i;

	i = 0;
	if (table->number_of_meals == 0)
		return ;
	else if (table->number_of_philos == 1)
	{
		//adicionar uma função para este caso
		return ;
	}
	else
	{
		while (i < table->number_of_philos)
		{
			handle_threads(table->philos[i].thread_id, CREATE);
			i++;
		}
	}
	//criar getters e setters booleanos para indicar em que pé estamos na refeição
	//iniciar a refeição dos filósofos -> indicando com o setter que irá começar
}
