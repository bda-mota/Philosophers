/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:42:43 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/02 20:47:41 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>

enum e_mode
{
	CREATE,
	JOIN,
	DETACH,
	INIT,
	DESTROY,
	LOCK,
	UNLOCK
};

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
	bool		full;
	long		last_meal_time;
	pthread_t	thread_id;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_table		*table; //para conseguir acessar os dados de table
}t_philo;

typedef struct s_table
{
	long	number_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_meals;
	long	start;
	bool	ended;
	t_fork	*forks;
	t_philo	*philos;
}t_table;

/* INIT */
int			set_the_dining_table(t_table *table);
void		give_birth_to_philos(t_table *table);
void		handle_mutexes(pthread_mutex_t mutex, int mode);
void		handle_threads(pthread_t thread, int mode);
void		*dinner(void);

/* UTILS */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*print_error(const char *error);
int			print_error_number(const char *error);
bool		is_digit(char c);
bool		is_space(char c);

/* PARSING */
int			parsing_input(t_table *table, char **argv);
const char	*check_input(const char *str);
long int	ft_atol(const char *nptr);

#endif
