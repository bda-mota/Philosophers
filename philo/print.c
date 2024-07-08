/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:04:46 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/08 17:05:14 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*print_error(const char *error)
{
	printf("Error: %s\n", error);
	return (NULL);
}

int	print_error_number(const char *error)
{
	printf("Error: %s\n", error);
	return (EXIT_FAILURE);
}

void	print_message(const char *message, t_philo *philos, int id)
{
	size_t	time;

	pthread_mutex_lock(philos->write_lock);
	time = get_current_time() - philos->start_at;
	if (!death(philos))
		printf("%ld %d %s\n", time, id, message);
	pthread_mutex_unlock(philos->write_lock);
}
