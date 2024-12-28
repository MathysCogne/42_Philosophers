/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:07:48 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 01:15:28 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	routine_eat(t_philosopher *philo)
{
	if (get_state_end(philo->param))
		return (1);
	update_last_meal(philo, get_time_simulation(philo));
	philo->count_to_eat++;
	print_state_philo(philo, LOG_EATING, get_time_simulation(philo));
	ft_sleep(philo->param->time_eat);
	return (0);
}
