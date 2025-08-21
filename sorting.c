/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:58:01 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/21 19:57:13 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	init_nodes(t_node *stack_a, t_node *stack_b)
{
	update_curr_pos(stack_a);
	update_curr_pos(stack_b);
	set_target_pos(stack_a, stack_b);
	update_costs(stack_a, stack_b);
}

void	sort_3(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > b && a > c)
		rotate_a(stack_a);
	else if (a < b && b > c)
		rev_rotate_a(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	pushed;

	pushed = 0;
	create_index(*stack_a);
	while (pushed < 2)
	{
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
		{
			push_b(stack_a, stack_b);
			pushed++;
		}
		else
			rotate_a(stack_a);
	}
	sort_3(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

static void	sort(t_node **stack_a)
{
	t_node	*head;
	int		pos;
	int		mov;
	int		size;

	pos = 0;
	mov = 0;
	head = *stack_a;
	size = count_nodes(*stack_a);
	while (head && head->index != 1)
	{
		pos++;
		head = head->next;
	}
	if (pos > 0)
	{
		mov = calc_cost(size, pos);
		rotate_a_alone(stack_a, mov);
	}
}

void	sort_all(t_node **stack_a, t_node **stack_b)
{
	int	index;

	index = -1;
	create_stack_b(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		init_nodes(*stack_a, *stack_b);
		index = set_cheapest(*stack_b);
		execute_move(stack_a, stack_b, index);
	}
	if (!is_sorted(*stack_a))
		sort(stack_a);
}
