/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+ +#+           */
/*   Created: 2024/12/12 20:03:14 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/12 20:46:28 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

/*
** How use my garbage collector ?
**
**	gc_init()
**		/ First step, initialize the garbage collector
**
**	gc_add(gc, (void *)ptr);
**		/ Add ptr to the garbage collector
**
**	gc_print_debug(gc);
**		/ Print all allocations in the garbage collector
**
**	gc_remove_one(gc, (void *)str)
**		/ Remove and free one ptr from the garbage collector
**
**	gc_clean(gc);
**		/ Finally, clean all allocations in the garbage collector
*/

/*
** Initialize the garbage collector
** - Return garbage collector head
*/
t_gc	*gc_init(void)
{
	t_gc	*gc;

	gc = malloc(sizeof(t_gc));
	if (!gc)
		return (NULL);
	gc->head = NULL;
	return (gc);
}

/*
** Add ptr to the garbage collector
** - Return 1 if fail
*/
short	gc_add(t_gc *gc, void *ptr)
{
	t_list	*new_node;

	if (!gc || !ptr)
		return (1);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (1);
	new_node->content = ptr;
	new_node->next = gc->head;
	gc->head = new_node;
	return (0);
}

/*
** Remove and free one ptr from the garbage collector
** - Return 1 if fail
*/
short	gc_remove_one(t_gc *gc, void *ptr)
{
	t_list	*tmp;
	t_list	*prev;

	if (!gc || !ptr)
		return (1);
	tmp = gc->head;
	prev = NULL;
	while (tmp)
	{
		if (tmp->content == ptr)
		{
			if (prev)
				prev->next = tmp->next;
			else
				gc->head = tmp->next;
			free(tmp->content);
			free(tmp);
			return (0);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}

/*
** Clean all allocations in the garbage collector
*/
void	gc_clean(t_gc *gc)
{
	t_list	*tmp;
	t_list	*to_free;

	if (!gc)
		return ;
	tmp = gc->head;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free->content);
		free(to_free);
	}
	free(gc);
}

/*
** Print all allocations in the garbage collector
*/
void	gc_print_debug(t_gc *gc)
{
	t_list	*tmp;
	int		i;

	if (!gc)
		return ;
	i = 0;
	tmp = gc->head;
	printf("List of all allocation in garbage collector:\n");
	while (tmp)
	{
		printf("%d: %p | %s\n", i, tmp->content, (char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
}
