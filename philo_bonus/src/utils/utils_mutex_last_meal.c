/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex_last_meal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:22:55 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 00:28:59 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	get_last_meal(t_philosopher *philo)
{
	size_t	last_meal;

	last_meal = philo->time_last_meal;
	return (last_meal);
}

void	update_last_meal(t_philosopher *philo, size_t new_value)
{
	philo->time_last_meal = new_value;
}
