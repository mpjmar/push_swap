/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:53:10 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/21 14:48:57 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	calc_cost(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

static int	calc_tot_cost(t_node *b)
{
	int	tot_cost;
	int	abs_a;
	int	abs_b;

	abs_a = b->cost_a;
	abs_b = b->cost_b;
	if ((abs_a >= 0) == (abs_b >= 0))
	{
		abs_a = neg_to_abs(abs_a);
		abs_b = neg_to_abs(abs_b);
		if (abs_a > abs_b)
			tot_cost = abs_a;
		else
			tot_cost = abs_b;
	}
	else
	{
		abs_a = neg_to_abs(abs_a);
		abs_b = neg_to_abs(abs_b);
		tot_cost = abs_a + abs_b;
	}
	return (tot_cost);
}

void	update_costs(t_node *stack_a, t_node *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = count_nodes(stack_a);
	size_b = count_nodes(stack_b);
	while (stack_b)
	{
		stack_b->cost_a = calc_cost(size_a, stack_b->target_pos);
		stack_b->cost_b = calc_cost(size_b, stack_b->curr_pos);
		stack_b = stack_b->next;
	}
}

int	set_cheapest(t_node *stack_b)
{
	t_node	*cheapest;
	int		min_cost;
	int		tot_cost;
	int		index;

	index = -1;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (stack_b)
	{
		tot_cost = calc_tot_cost(stack_b);
		if (tot_cost < min_cost)
		{
			min_cost = tot_cost;
			cheapest = stack_b;
		}
		stack_b = stack_b->next;
	}
	index = cheapest->index;
	return (index);
}
