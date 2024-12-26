/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:07:48 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/26 18:24:45 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	routine_sleep(t_env *env, t_philosopher *philo)
{
	(void)env;
	print_state_philo(philo, LOG_SLEEP, 4242);
	return (0);
}

short	routine_eat(t_env *env, t_philosopher *philo)
{
	(void)env;
	print_state_philo(philo, LOG_EATING, 4242);
	return (0);
}

short	routine_think(t_env *env, t_philosopher *philo)
{
	(void)env;
	print_state_philo(philo, LOG_THINKING, 4242);
	return (0);
}