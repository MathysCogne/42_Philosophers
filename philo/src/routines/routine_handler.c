/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:34 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 01:22:48 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_handler(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!get_state_end(philo->param))
	{
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
	return (NULL);
}
