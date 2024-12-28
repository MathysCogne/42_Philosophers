/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex_state_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:14:11 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 23:26:05 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

short	get_state_end(t_param *param)
{
	short	state;

	sem_wait(param->sem_state_end);
	state = param->state_end;
	sem_post(param->sem_state_end);
	return (state);
}

void	update_state_end(t_param *param, int new_value)
{
	sem_wait(param->sem_state_end);
	param->state_end = new_value;
	sem_post(param->sem_state_end);
}
