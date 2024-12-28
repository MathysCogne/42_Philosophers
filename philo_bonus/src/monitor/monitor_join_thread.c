/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_join_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:07:26 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 00:01:29 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

short	join_thread(t_env *env)
{
	size_t	i;
	int		status;

	i = 0;
	while (i < env->param->nb_philo)
	{
		waitpid(env->philo[i]->pid, &status, 0);
		printf("UN PHILO MORT\n");
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 1)
			{
				printf(">> KILL ALL\n");
				// kill_all_philo(env);
				break ;
			}
		}
		i++;
	}
	return (0);
}
