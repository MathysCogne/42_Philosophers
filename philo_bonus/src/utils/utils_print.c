/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:20:51 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 23:26:42 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// imestamp_in_ms X has taken a fork
// ◦timestamp_in_ms X is eating
// ◦timestamp_in_ms X is sleeping
// ◦timestamp_in_ms X is thinking
// ◦timestamp_in_ms X died

void	print_state_philo(t_philosopher *philo, char *log, size_t timestamp)
{
	if (get_state_end(philo->param) && log[0] != 'd')
		return ;
	sem_wait(philo->param->sem_printf);
	printf("%zu %zu %s\n", timestamp, philo->id + 1, log);
	sem_post(philo->param->sem_printf);
}
