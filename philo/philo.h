/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:42:43 by bda-mota          #+#    #+#             */
/*   Updated: 2024/07/04 13:08:24 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <errno.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>

/* ENUMS */
typedef enum e_mode
{
	CREATE,
	JOIN,
	DETACH,
	INIT,
	DESTROY,
	LOCK,
	UNLOCK
}t_mode;

typedef struct s_philo
{
	int				id;
	int				*dead;
	bool			full;
	long			meals_eaten;
	long			last_meal_time;
	t_table			*table;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
}t_philo;

typedef struct s_table
{
	int				dead_flag;
	long			number_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_meals;
	long			start_time;
	bool			ended;
	bool			all_born;
	t_philo			*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}t_table;

/* INIT */
void			set_the_dining_table(t_table *table, pthread_mutex_t *forks);
void			init_forks(pthread_mutex_t *forks, int number_of_philos);
void			create_philos(t_philo *philos, t_table *table,
					pthread_mutex_t *forks);
size_t			get_current_time(void);

/* MUTEXES */
void			handle_mutexes(pthread_mutex_t mutex, t_mode mode);
void			handle_mutexes_erros(int status, t_mode mode);
pthread_mutex_t	get_forks(pthread_mutex_t *forks);

/* UTILS */
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*print_error(const char *error);
int				print_error_number(const char *error);
int				ft_usleep(size_t milliseconds);

/* PARSING */
int				parsing_input(t_table *table, char **argv);
const char		*check_input(const char *str);
long int		ft_atol(const char *nptr);
bool			is_digit(char c);
bool			is_space(char c);

/* THREADS */
int				dinners_end(t_philo *philos, t_table *table, const char *error);

/* ROUTINE */
void			*routine(t_philo *philo);
void			*monitor(t_table *table);

#endif
