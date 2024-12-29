/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_kill_all_philo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:05:13 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 02:05:30 by mcogne--         ###   ########.fr       */
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
