/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:44:34 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/27 03:01:32 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// NOTE: Creer un mutex pour le demarrage des philos afin qu'il demarre tous en meme temps ???
void	*routine_handler(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!philo->param.state_end)
	{
		if (routine_take_fork(philo))
			break ;
		if (routine_eat(philo))
			break ;
		if (routine_free_fork(philo))
			break ;
		if (routine_sleep(philo))
			break ;
		if (routine_think(philo))
			break ;
	}
	return (NULL);
}
