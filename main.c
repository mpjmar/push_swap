/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:57:14 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/21 19:00:43 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
		manage_two_args(argv, stack_a);
	else if (argc > 2)
	{
		if (args_to_stack(argv + 1, &stack_a))
		{
			free_stack(&stack_a);
			return (1);
		}
	}
	take_actions(stack_a, stack_b);
}

int	manage_two_args(char **argv, t_node *stack_a)
{
	char	**numbers;

	numbers = ft_split(argv[1]);
	if (!numbers)
		return (1);
	if (args_to_stack(numbers, &stack_a))
	{
		free_split(numbers);
		free_stack(&stack_a);
		return (1);
	}
	free_split(numbers);
	return (0);
}

int	take_actions(t_node *stack_a, t_node *stack_b)
{
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	create_index(stack_a);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	int	nodes;

	nodes = count_nodes(*stack_a);
	if (nodes == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a(stack_a);
	}
	else if (nodes == 3)
		sort_3(stack_a);
	else if (nodes == 5)
		sort_5(stack_a, stack_b);
	else
		sort_all(stack_a, stack_b);
}
