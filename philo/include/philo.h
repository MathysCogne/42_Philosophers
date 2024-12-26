/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:14:59 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/26 18:21:41 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock
/*******************************/
/*           DEFINE            */
/*******************************/
# define LOG_TAKE_FORK "has taken a fork"
# define LOG_EATING "is eating"
# define LOG_SLEEP "is sleeping"
# define LOG_THINKING "is thinking"
# define LOG_DIED "died"

# define PARSING_MIN 0

# define INT_MIN -2147483648
# define INT_MAX 2147483647

/*******************************/
/*           STRUCT            */
/*******************************/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_gc
{
	t_list			*head;
}					t_gc;

typedef struct s_param
{
	size_t			nb_philo;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			nb_to_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf_lock;
	int				state_end;
}					t_param;

typedef struct s_philosopher
{
	size_t			id;
	pthread_t		thread;
	size_t			time_last_meal;
	size_t			count_to_eat;
	struct s_param	param;
}					t_philosopher;

typedef struct s_env
{
	t_param			param;
	t_gc			*gc;
	t_philosopher	*philo;
}					t_env;

/*******************************/
/*            PHILO            */
/*******************************/
short				parsing(t_env *env, char **argv);

short				routine_think(t_env *env, t_philosopher *philo);
short				routine_eat(t_env *env, t_philosopher *philo);
short				routine_sleep(t_env *env, t_philosopher *philo);

void				print_state_philo(t_philosopher *philo, char *log,
						size_t timestamp);

/*******************************/
/*            UTILS            */
/*******************************/
long long			ft_atoll(const char *str);
short				is_int(size_t size, char **arg);
size_t				ft_strlen(char *s);
void				clean(t_env *env);

/*******************************/
/*       GARBAGE COLLECTOR     */
/*******************************/
t_gc				*gc_init(void);
short				gc_add(t_gc *gc, void *ptr);
short				gc_remove_one(t_gc *gc, void *ptr);
void				gc_clean(t_gc *gc);
void				gc_print_debug(t_gc *gc);

/*******************************/
/*            DEBUG            */
/*******************************/
void				debug_print_param(t_env *env);

#endif