/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:58:01 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/19 16:28:20 by maria-j2         ###   ########.fr       */
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

static void	execute_move(t_node **stack_a, t_node **stack_b, int index)
{
	int		cost_a;
	int		cost_b;
	t_node	*temp;

	temp = *stack_b;
	while (temp)
	{
		if (temp->index == index)
		{
			cost_a = (*stack_b)->cost_a;
			cost_b = (*stack_b)->cost_b;
			temp = NULL;
		}
		else
			temp = temp->next;
	}
	rotate_pos(stack_a, stack_b, cost_a, cost_b);
	rotate_neg(stack_a, stack_b, cost_a, cost_b);
	push_a(stack_b, stack_a);
}

static void	sort(t_node **stack_a)
{
	t_node	*head;
	int		pos;
	int		mov;

	pos = 0;
	mov = 0;
	head = *stack_a;
	while (head->index != 1)
	{
		pos++;
		head = head->next;
	}
	mov = calc_cost(count_nodes(*stack_a), pos);
	rotate_a_alone(stack_a, mov);
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
		//print_stack(*stack_a, 'A');
		//print_stack(*stack_b, 'B');
		index = set_cheapest(*stack_b);
		execute_move(stack_a, stack_b, index);
	}
	//printf("FUERA DEL WHILE\n");
	//print_stack(*stack_a, 'A');
	//print_stack(*stack_b, 'B');
	if (!is_sorted(*stack_a))
		sort(stack_a);
	//printf("DESPUES DE IS SORTED\n");
	//print_stack(*stack_a, 'A');
	//print_stack(*stack_b, 'B');
}
