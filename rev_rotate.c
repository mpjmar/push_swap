/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:21:49 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/15 19:15:47 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static t_node	*get_prev_node(t_node *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

static void	rev_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*prev_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	prev_last = get_prev_node(*stack);
	last->next = (*stack);
	prev_last->next = NULL;
	*stack = last;
}

void	rev_rotate_a(t_node **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_node **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr_rotate(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
