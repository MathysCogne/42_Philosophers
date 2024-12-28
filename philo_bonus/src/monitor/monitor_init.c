/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:11:06 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 00:52:22 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all_philo(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->param->nb_philo)
	{
		if (env->philo[i]->pid > 0)
			kill(env->philo[i]->pid, SIGTERM);
		i++;
	}
}

void	monitor_handler(t_env *env)
{
	size_t	i;
	int		status;
	size_t	finished_count;

	finished_count = 0;
	while (1)
	{
		i = 0;
		while (i < env->param->nb_philo)
		{
			if (waitpid(env->philo[i]->pid, &status, WNOHANG) > 0)
			{
				if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
				{
					printf("Philosopher %zu died\n", i + 1);
					kill_all_philo(env);
					return ;
				}
				else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
				{
					finished_count++;
				}
			}
			i++;
		}
		if (finished_count == env->param->nb_philo)
		{
			kill_all_philo(env);
			return ;
		}
		usleep(1000);
	}
}

short	init_monitor(t_env *env)
{
	monitor_handler(env);
	return (0);
}
