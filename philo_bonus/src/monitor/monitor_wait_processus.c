/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_wait_processus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:07:26 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 02:19:00 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

short	wait_processus(t_env *env)
{
	size_t	i;
	int		status;

	i = 0;
	while (i < env->param->nb_philo)
	{
		waitpid(env->philo[i]->pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 1)
			{
				kill_all_philo(env);
				break ;
			}
		}
		i++;
	}
	return (0);
}
