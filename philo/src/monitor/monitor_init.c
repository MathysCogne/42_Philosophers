/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:11:06 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/27 04:15:58 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_handler(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
}

short	init_monitor(t_env *env)
{
	if (env->param.nb_to_eat != -1) // MONITOR STATE
		;
	pthread_create(&env->monitor, NULL, monitor_handler, env);
	return (0);
}