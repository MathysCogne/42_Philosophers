/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:07:48 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 01:47:03 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Lock the lower fork first (!DEADLOCK)
** For always lock/unlock in same order
*/
short	routine_take_fork(t_philosopher *philo)
{
	if (philo->param->nb_philo == 1)
	{
		print_state_philo(philo, LOG_TAKE_FORK, get_time_simulation(philo));
		ft_sleep(philo->param->time_die);
		return (1);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->param->forks[philo->id]);
		pthread_mutex_lock(&philo->param->forks[(philo->id + 1)
			% philo->param->nb_philo]);
	}
	else
	{
		pthread_mutex_lock(&philo->param->forks[(philo->id + 1)
			% philo->param->nb_philo]);
		pthread_mutex_lock(&philo->param->forks[philo->id]);
	}
	print_state_philo(philo, LOG_TAKE_FORK, get_time_simulation(philo));
	print_state_philo(philo, LOG_TAKE_FORK, get_time_simulation(philo));
	return (0);
}

/*
** Unlock the hight fork first (!DEADLOCK)
*/
short	routine_free_fork(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->param->forks[philo->id]);
		pthread_mutex_unlock(&philo->param->forks[(philo->id + 1)
			% philo->param->nb_philo]);
	}
	else
	{
		pthread_mutex_unlock(&philo->param->forks[(philo->id + 1)
			% philo->param->nb_philo]);
		pthread_mutex_unlock(&philo->param->forks[philo->id]);
	}
	return (0);
}
