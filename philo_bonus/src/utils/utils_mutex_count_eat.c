/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex_count_eat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:22:55 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 00:29:16 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	get_count_eat(t_philosopher *philo)
{
	size_t	count_eat;

	count_eat = philo->count_to_eat;
	return (count_eat);
}

void	increment_count_eat(t_philosopher *philo)
{
	philo->count_to_eat++;
}
