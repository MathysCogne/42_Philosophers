/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:20:51 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/27 02:14:01 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// imestamp_in_ms X has taken a fork
// ◦timestamp_in_ms X is eating
// ◦timestamp_in_ms X is sleeping
// ◦timestamp_in_ms X is thinking
// ◦timestamp_in_ms X died

void	print_state_philo(t_philosopher *philo, char *log, size_t timestamp)
{
	pthread_mutex_lock(&philo->param.printf_lock);
	printf("%zu %zu %s\n", timestamp, philo->id, log);
	pthread_mutex_unlock(&philo->param.printf_lock);
}
