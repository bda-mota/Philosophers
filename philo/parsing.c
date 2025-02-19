/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:58:39 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/12 18:08:45 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing_input(t_table *table, char **argv)
{
	table->number_of_philos = ft_atol(argv[1]);
	if (table->number_of_philos == 0)
		return (0);
	table->time_to_die = ft_atol(argv[2]);
	if (table->time_to_die == 0)
		return (0);
	table->time_to_eat = ft_atol(argv[3]);
	if (table->time_to_eat == 0)
		return (0);
	table->time_to_sleep = ft_atol(argv[4]);
	if (table->time_to_sleep == 0)
		return (0);
	if (argv[5])
		table->number_of_meals = ft_atol(argv[5]);
	else
		table->number_of_meals = -1;
	return (1);
}

const char	*check_input(const char *str)
{
	size_t		i;
	size_t		len;
	const char	*nbr;

	i = 0;
	len = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (print_error("only positive numbers allowed"));
	if (!is_digit(str[i]) || str[i] == '0')
		return (print_error("incorrect input"));
	nbr = &str[i];
	while (is_digit(str[i]))
	{
		len++;
		i++;
	}
	if (!is_digit(str[i]) && str[i] != '\0' && !is_space(str[i]))
		return (print_error("incorrect iput"));
	if (len > 10 || (len == 10 && ft_strncmp(nbr, "2147483647", 10) > 0))
		return (print_error("number too big"));
	return (nbr);
}

int	ft_atol(const char *nptr)
{
	int					i;
	unsigned long long	result;

	i = 0;
	result = 0;
	nptr = check_input(nptr);
	if (!nptr)
		return (0);
	while (is_digit(nptr[i]))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result);
}

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
