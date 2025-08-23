/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:43:10 by mpazjimenez       #+#    #+#             */
/*   Updated: 2025/08/22 18:45:39 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_node	*create_new_node(void)
{
	t_node	*new_node;

	new_node = NULL;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = 0;
	new_node->index = 0;
	new_node->curr_pos = 0;
	new_node->target_pos = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	return (new_node);
}

t_node	*get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*aux;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	aux = get_last_node(*stack);
	aux->next = new_node;
}

static int	check_and_fill_node(char **numbers, t_node **stack, int i)
{
	t_node	*new_node;
	long	nbr;

	if (!is_numeric(numbers[i]))
	{
		free_and_write(stack);
		return (1);
	}
	new_node = create_new_node();
	if (!new_node)
		return (1);
	nbr = ft_atol(numbers[i]);
	if (is_int(nbr) && not_duplicated(*stack, (int)nbr))
		new_node->value = (int)nbr;
	else
	{
		free_and_write(stack);
		free(new_node);
		return (1);
	}
	add_node_back(stack, new_node);
	return (0);
}

int	args_to_stack(char **numbers, t_node **stack)
{
	int		i;

	i = 0;
	while (numbers[i])
	{
		if (check_and_fill_node(numbers, stack, i))
			return (1);
		i++;
	}
	return (0);
}
