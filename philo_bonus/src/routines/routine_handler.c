/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:34 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 03:01:48 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*routine_monitor_process(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		if (get_delay_last_meal(philo) > philo->param->time_die)
		{
			update_state_end(philo->param, 1);
			print_state_philo(philo, LOG_DIED, get_time_simulation(philo));
			break ;
		}
		usleep(10);
	}
	return (NULL);
}

void	*routine_handler(t_philosopher *philo)
{
	philo->param->start_time = get_time();
	pthread_create(&philo->monitor_processus, NULL, routine_monitor_process,
		philo);
	while (!get_state_end(philo->param))
	{
		if (get_count_eat(philo) >= philo->param->nb_to_eat)
			exit(0);
		if (routine_take_fork(philo))
			break ;
		if (routine_eat(philo))
		{
			routine_free_fork(philo);
			break ;
		}
		if (routine_free_fork(philo))
			break ;
		if (routine_sleep(philo))
			break ;
		if (philo->param->nb_philo % 2 != 0)
			routine_think(philo);
	}
	pthread_join(philo->monitor_processus, NULL);
	exit(1);
}
