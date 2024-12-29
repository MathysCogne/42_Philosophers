/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:07:48 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 01:06:43 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

short	routine_take_fork(t_philosopher *philo)
{
	if (philo->param->nb_philo == 1)
	{
		print_state_philo(philo, LOG_TAKE_FORK, get_time_simulation(philo));
		ft_sleep(philo->param->time_die);
		print_state_philo(philo, LOG_DIED, get_time_simulation(philo));
		return (1);
	}
	sem_wait(philo->param->sem_forks);
	print_state_philo(philo, LOG_TAKE_FORK, get_time_simulation(philo));
	sem_wait(philo->param->sem_forks);
	print_state_philo(philo, LOG_TAKE_FORK, get_time_simulation(philo));
	return (0);
}

short	routine_free_fork(t_philosopher *philo)
{
	sem_post(philo->param->sem_forks);
	sem_post(philo->param->sem_forks);
	return (0);
}
