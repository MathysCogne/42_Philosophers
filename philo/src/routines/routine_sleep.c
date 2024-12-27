/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:07:48 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/27 02:18:40 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	routine_sleep(t_philosopher *philo)
{
	if (philo->param.state_end == 1)
		return (1);
	print_state_philo(philo, LOG_SLEEP, get_time_simulation(philo));
	// usleep(philo->param.time_sleep * 1000);
	ft_sleep(philo->param.time_sleep);
	return (0);
}
