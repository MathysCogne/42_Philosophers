/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:11:06 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 01:28:17 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	check_meal_philo(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->param->nb_philo)
	{
		if (get_delay_last_meal(env->philo[i]) > env->param->time_die)
		{
			update_state_end(env->param, 1);
			usleep(100);
			print_state_philo(env->philo[i], LOG_DIED,
				get_time_simulation(env->philo[i]));
			return (1);
		}
		i++;
	}
	return (0);
}

void	*routine_monitor_handler(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	while (1)
	{
		if (get_state_end(env->param))
			break ;
		if (check_meal_philo(env))
			break ;
		usleep(100);
	}
	return (NULL);
}

short	init_monitor(t_env *env)
{
	pthread_create(&env->monitor_thread, NULL, routine_monitor_handler, env);
	return (0);
}
