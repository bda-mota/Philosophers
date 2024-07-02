/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:42:43 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/02 15:05:42 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>

/* STRUCTS */
typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				id;
}t_fork;

typedef struct s_philo
{
	int			id;
	long		meals;
	int			full;
	int			last_meal_time;
	pthread_t	thread_id;
	t_fork		*left_fork;
	t_fork		*right_fork;
}t_philo;

typedef struct s_table
{
	int	number_of_philosphers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
}t_table;

/* UTILS */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*print_error(const char *error);
bool		is_digit(char c);
bool		is_space(char c);

/* PARSING */
int			parsing_input(t_table *table, char **argv);
const char	*check_input(const char *str);
long int	ft_atol(const char *nptr);

#endif
