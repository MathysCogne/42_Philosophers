/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:20:51 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 01:25:54 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state_philo(t_philosopher *philo, char *log, size_t timestamp)
{
	if (get_state_end(philo->param) && log[0] != 'd')
		return ;
	pthread_mutex_lock(&philo->param->lock_printf);
	printf("%zu %zu %s\n", timestamp, philo->id + 1, log);
	pthread_mutex_unlock(&philo->param->lock_printf);
}
