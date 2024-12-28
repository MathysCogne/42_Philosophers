/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:14:59 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/27 23:25:42 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
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

# define PARSING_MIN 1

# define INT_MIN -2147483648
# define INT_MAX 2147483647

/*******************************/
/*            INIT             */
/*******************************/
short		init_fork(t_env *env);
short		init_param(t_env *env, char **argv);
short		init_philosopher(t_env *env);

/*******************************/
/*         MONITORING          */
/*******************************/
short		init_monitor(t_env *env);
short		join_thread(t_env *env);

/*******************************/
/*         ROUTINES            */
/*******************************/
void		*routine_handler(void *arg);
short		routine_take_fork(t_philosopher *philo);
short		routine_eat(t_philosopher *philo);
short		routine_free_fork(t_philosopher *philo);
short		routine_sleep(t_philosopher *philo);
short		routine_think(t_philosopher *philo);

/*******************************/
/*            UTILS            */
/*******************************/
size_t		get_last_meal(t_philosopher *philo);
void		update_last_meal(t_philosopher *philo, size_t new_value);
short		get_state_end(t_param *param);
void		update_state_end(t_param *param, int new_value);
void		clean(t_env *env);
void		ft_sleep(size_t time);
size_t		get_time(void);
size_t		get_delay_last_meal(t_philosopher *philo);
size_t		get_time_simulation(t_philosopher *philo);
void		print_state_philo(t_philosopher *philo, char *log,
				size_t timestamp);

/*******************************/
/*            DEBUG            */
/*******************************/
void		debug_print_param(t_env *env);

/*******************************/
/*             LIB             */
/*******************************/
long long	ft_atoll(const char *str);
short		is_int(size_t size, char **arg);
size_t		ft_strlen(char *s);
void		clean(t_env *env);

/*******************************/
/*       GARBAGE COLLECTOR     */
/*******************************/
t_gc		*gc_init(void);
short		gc_add(t_gc *gc, void *ptr);
short		gc_remove_one(t_gc *gc, void *ptr);
void		gc_clean(t_gc *gc);
void		gc_print_debug(t_gc *gc);

#endif