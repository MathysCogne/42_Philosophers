/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex_count_eat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:22:55 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 01:48:10 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_count_eat(t_philosopher *philo)
{
	size_t	count_eat;

	pthread_mutex_lock(&philo->lock_count_meal);
	count_eat = philo->count_to_eat;
	pthread_mutex_unlock(&philo->lock_count_meal);
	return (count_eat);
}

void	increment_count_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->lock_count_meal);
	philo->count_to_eat++;
	pthread_mutex_unlock(&philo->lock_count_meal);
}
