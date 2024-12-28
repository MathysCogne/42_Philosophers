/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:34 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 01:31:13 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO A SUPR MMUTEX LOCKFORKS
// pthread_mutex_lock(&philo->param->lock_forks);
// pthread_mutex_unlock(&philo->param->lock_forks);
void	*routine_handler(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!get_state_end(philo->param))
	{
		if (routine_take_fork(philo))
			break ;
		if (routine_eat(philo))
			break ;
		if (routine_free_fork(philo))
			break ;
		if (routine_sleep(philo))
			break ;
		if (philo->param->nb_philo % 2 != 0)
			routine_think(philo);
	}
	return (NULL);
}
