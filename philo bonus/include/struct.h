/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:49:43 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 20:15:05 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

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
	size_t			start_time;
	sem_t			sem_forks;
	sem_t			sem_state_end;
	sem_t			sem_printf;
	volatile int	state_end;
}					t_param;

typedef struct s_philosopher
{
	size_t			pid;
	size_t			id;
	pthread_t		thread;
	size_t			time_last_meal;
	// pthread_mutex_t	lock_last_meal;
	size_t			count_to_eat;
	// pthread_mutex_t	lock_count_eat;
	struct s_param	*param;
}					t_philosopher;

typedef struct s_env
{
	t_param			*param;
	t_gc			*gc;
	t_philosopher	**philo;
	pthread_t		monitor_thread;
}					t_env;

#endif