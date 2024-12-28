/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:50:05 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/27 23:39:12 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// TODO CHECK DATA RACE PARAM START TIME NON ?
size_t	get_time_simulation(t_philosopher *philo)
{
	return (get_time() - philo->param->start_time);
}

size_t	get_delay_last_meal(t_philosopher *philo)
{
	size_t	acutal_time;
	size_t	last_meal;

	acutal_time = get_time_simulation(philo);
	last_meal = get_last_meal(philo);
	return (acutal_time - last_meal);
}

void	ft_sleep(size_t time)
{
	size_t	current_time;

	current_time = get_time();
	while ((get_time() - current_time) < time)
		usleep(100);
}
