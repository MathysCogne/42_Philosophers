/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:34:02 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/28 20:13:21 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

short	init_fork(t_env *env)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_state_end");
	sem_unlink("/sem_printf");
	sem_open("/sem_forks", SEM_CREATE | SEM_ONLY, SEM_PERMS, env->param->nb_philo);
	sem_open("/sem_state_end", SEM_CREATE | SEM_ONLY, SEM_PERMS, 1);
	sem_open("/sem_printf", SEM_CREATE | SEM_ONLY, SEM_PERMS, 1);
	return (0);
}
