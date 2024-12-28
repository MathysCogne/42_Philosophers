/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex_state_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:14:11 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/27 23:23:08 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	get_state_end(t_param *param)
{
	short	state;

	pthread_mutex_lock(&param->lock_state_end);
	state = param->state_end;
	pthread_mutex_unlock(&param->lock_state_end);
	return (state);
}

void	update_state_end(t_param *param, int new_value)
{
	pthread_mutex_lock(&param->lock_state_end);
	param->state_end = new_value;
	pthread_mutex_unlock(&param->lock_state_end);
}
