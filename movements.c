/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:09:53 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/21 18:20:39 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	rotate_pos(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr_rotate(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rotate_a(stack_a);
		cost_a--;
	}
	while (cost_b > 0)
	{
		rotate_b(stack_b);
		cost_b--;
	}
}

void	rotate_neg(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr_rotate(stack_a, stack_b);
		cost_a++;
		cost_b++;
	}
	while (cost_a < 0)
	{
		rev_rotate_a(stack_a);
		cost_a++;
	}
	while (cost_b < 0)
	{
		rev_rotate_b(stack_b);
		cost_b++;
	}
}

void	rotate_a_alone(t_node **stack_a, int cost_a)
{
	while (cost_a > 0)
	{
		rotate_a(stack_a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rev_rotate_a(stack_a);
		cost_a++;
	}
}

void	execute_move(t_node **stack_a, t_node **stack_b, int index)
{
	int		cost_a;
	int		cost_b;
	t_node	*temp;

	cost_a = 0;
	cost_b = 0;
	temp = *stack_b;
	while (temp)
	{
		if (temp->index == index)
		{
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
			temp = NULL;
		}
		else
			temp = temp->next;
	}
	rotate_pos(stack_a, stack_b, cost_a, cost_b);
	rotate_neg(stack_a, stack_b, cost_a, cost_b);
	push_a(stack_b, stack_a);
}
