/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:29:22 by mpazjimenez       #+#    #+#             */
/*   Updated: 2025/08/18 18:16:17 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"
#include <stdio.h> // QUITAR!!!

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

long	ft_atol(const char *str)
{
	long	resul;
	int		sign;

	resul = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		resul = resul * 10 + *str - '0';
		str++;
	}
	return (resul * sign);
}

void	free_stack(t_node **stack)
{
	t_node	*next;

	if (!stack)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	neg_to_abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

void	print_stack(t_node *stack, char name) // QUITAR!!
{
	printf("--- Stack %c ---\n", name);
	if (!stack)
	{
		printf("(null)\n");
		return ;
	}
	while (stack)
	{
		printf("value: %d, index: %d, curr_pos: %d, target_pos: %d, "
			"cost_a: %d, cost_b: %d\n",
			stack->value, stack->index, stack->curr_pos, stack->target_pos,
			stack->cost_a, stack->cost_b);
		stack = stack->next;
	}
	printf("---------------\n");
}
