/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:11:06 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 02:19:49 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

short	monitor_handler(t_env *env)
{
	size_t	i;
	int		status;
	size_t	philo_finish_eat;

	philo_finish_eat = 0;
	while (1)
	{
		i = 0;
		while (i < env->param->nb_philo)
		{
			if (waitpid(env->philo[i]->pid, &status, WNOHANG) > 0)
			{
				if (WEXITSTATUS(status) == 1)
					return (kill_all_philo(env), 1);
				else if (WEXITSTATUS(status) == 0)
					philo_finish_eat++;
			}
			i++;
		}
		if (philo_finish_eat == env->param->nb_philo)
			return (kill_all_philo(env), 1);
		usleep(200);
	}
}

short	init_monitor(t_env *env)
{
	monitor_handler(env);
	return (0);
}
