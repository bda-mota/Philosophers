/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:05:14 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/05 14:55:17 by bda-mota         ###   ########.fr       */
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
	if (!dead(philos))
		printf("%ld %d %s\n", time, id, message);
	pthread_mutex_unlock(philos->write_lock);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
