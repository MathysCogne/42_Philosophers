/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:14:59 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/25 18:03:03 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock
/*******************************/
/*           DEFINE            */
/*******************************/
# define INT_MIN -2147483648
# define INT_MAX 2147483647

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
}					t_param;

typedef struct s_env
{
	t_param			param;
	t_gc			gc;
}					t_env;

/*******************************/
/*            PHILO            */
/*******************************/

/*******************************/
/*            UTILS            */
/*******************************/
long long			ft_atoll(const char *str);
short				is_int(size_t size, char **arg);
size_t				ft_strlen(char *s);

/*******************************/
/*       GARBAGE COLLECTOR     */
/*******************************/
t_gc				*gc_init(void);
short				gc_add(t_gc *gc, void *ptr);
short				gc_remove_one(t_gc *gc, void *ptr);
void				gc_clean(t_gc *gc);
void				gc_print_debug(t_gc *gc);

#endif