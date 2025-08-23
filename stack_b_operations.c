/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:41:27 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/23 19:35:32 by maria-j2         ###   ########.fr       */
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

/* static void	move_nodes(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	size;
	int	nodes;

	max = count_nodes(*stack_a);
	size = max;
	while (size > 0)
	{
		nodes = count_nodes(*stack_a);
		if ((max % 2 == 0) && ((*stack_a)->index <= (max / 2)) && nodes > 3)
			push_b(stack_a, stack_b);
		else if ((max % 2 != 0)
			&& ((*stack_a)->index <= (max / 2) + 1) && nodes > 3)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		size--;
	}
}

void	create_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	size;

	move_nodes(stack_a, stack_b);
	max = count_nodes(*stack_a);
	size = count_nodes(*stack_a);
	while (size > 3)
	{
		if ((*stack_a)->index != max)
		{
			push_b(stack_a, stack_b);
			size--;
		}
		else
			rotate_a(stack_a);
	}
} */

void	create_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	size;

	max = count_nodes(*stack_a);
	
	size = count_nodes(*stack_a);
	while (size > 3)
	{
		if ((*stack_a)->index != max || (*stack_a)->index <= (max / 2))
		{
			push_b(stack_a, stack_b);
			size--;
		}
		else
			rotate_a(stack_a);
	}
}

static void	set_target_p(t_node *stack_a, t_node *stack_b,
	t_node *cursor_a, int target_p)
{
	int		target_index;

	cursor_a = stack_a;
	target_index = INT_MAX;
	while (cursor_a)
	{
		if (cursor_a->index < stack_b->index)
		{
			target_index = cursor_a->index;
			target_p = cursor_a->curr_pos;
		}
		cursor_a = cursor_a->next;
	}
}

void	set_target_pos(t_node *stack_a, t_node *stack_b)
{
	int		target_index;
	int		target_p;
	t_node	*cursor_a;

	while (stack_b)
	{
		target_index = INT_MAX;
		target_p = -1;
		cursor_a = stack_a;
		while (cursor_a)
		{
			if (cursor_a->index > stack_b->index
				&& cursor_a->index < target_index)
			{
				target_index = cursor_a->index;
				target_p = cursor_a->curr_pos;
			}
			cursor_a = cursor_a->next;
		}
		if (target_p == -1)
			set_target_p(stack_a, stack_b, cursor_a, target_p);
		stack_b->target_pos = target_p;
		stack_b = stack_b->next;
	}
}
