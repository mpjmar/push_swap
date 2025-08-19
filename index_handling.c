/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:53:53 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/16 14:55:12 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static t_node	*find_min_node(t_node *stack)
{
	t_node	*min_node;
	int		min_value;

	if (!stack)
		return (NULL);
	min_node = NULL;
	min_value = INT_MAX;
	while (stack)
	{
		if (stack->value < min_value && stack->index == 0)
		{
			min_value = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	create_index(t_node *stack)
{
	int		idx;
	t_node	*min_node;

	if (!stack)
		return ;
	idx = 1;
	min_node = find_min_node(stack);
	while (min_node != NULL)
	{
		min_node->index = idx;
		idx++;
		min_node = find_min_node(stack);
	}
}

void	update_curr_pos(t_node *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack)
	{
		stack->curr_pos = i;
		i++;
		stack = stack->next;
	}
}
