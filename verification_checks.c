/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_checks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:03:17 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/17 13:55:24 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	not_duplicated(t_node *stack, int number)
{
	while (stack)
	{
		if (number == stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_int(long number)
{
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	return (1);
}

int	is_sorted(t_node *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
