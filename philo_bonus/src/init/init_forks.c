/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:34:02 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/29 00:21:03 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

short	init_fork(t_env *env)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_state_end");
	sem_unlink("/sem_printf");
	env->param->sem_forks = sem_open("/sem_forks", O_CREAT | O_EXCL, SEM_PERMS,
			env->param->nb_philo);
	env->param->sem_state_end = sem_open("/sem_state_end", O_CREAT | O_EXCL,
			SEM_PERMS, 1);
	env->param->sem_printf = sem_open("/sem_printf", O_CREAT | O_EXCL,
			SEM_PERMS, 1);
	return (0);
}
