/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:07:48 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 01:30:40 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	routine_sleep(t_philosopher *philo)
{
	if (get_state_end(philo->param))
		return (1);
	print_state_philo(philo, LOG_SLEEP, get_time_simulation(philo));
	ft_sleep(philo->param->time_sleep);
	return (0);
}
