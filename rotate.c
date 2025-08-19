/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:30:58 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/11 16:37:39 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	last = get_last_node(*stack);
	last->next = (*stack);
	last->next->next = NULL;
	(*stack) = temp;
}

void	rotate_a(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr_rotate(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
