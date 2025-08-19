/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:41:27 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/19 18:13:35 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	count_nodes(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	create_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	size;
	int	nodes;

	max = count_nodes(*stack_a);
	size = max;
	while (size > 0)
	{
		nodes = count_nodes(*stack_a);
		if ((max % 2 == 0) && (*stack_a)->index <= max / 2 && nodes > 3)
			push_b(stack_a, stack_b);
		else if ((max % 2 != 0) && (*stack_a)->index <= (max / 2) + 1 && nodes > 3)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		size--;
	}
	size = count_nodes(*stack_a);
	while (size > 3)
	{
		push_b(stack_a, stack_b);
		size--;
	}
}

void	set_target_pos(t_node *stack_a, t_node *stack_b)
{
	int		diff;
	int		target;
	int		idx_b;
	t_node	*init_a;

	target = -1;
	init_a = stack_a;
	while (stack_b)
	{
		diff = INT_MAX;
		idx_b = stack_b->index;
		while (stack_a)
		{
			if (idx_b < stack_a->index && (stack_a->index - idx_b) < diff)
			{
				diff = stack_a->index - idx_b;
				target = stack_a->curr_pos;
			}
			stack_a = stack_a->next;
		}
		stack_a = init_a;
		if (target == -1)
		{
			while (stack_a)
			{
				if (stack_a->index < diff)
				{
					diff = stack_a->index;
					target = stack_a->curr_pos;
				}
				stack_a = stack_a->next;
			}
		}
		stack_b->target_pos = target;
		stack_b = stack_b->next;
	}
}
