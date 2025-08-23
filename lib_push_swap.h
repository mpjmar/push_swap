/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:56:36 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/23 18:18:19 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // BORRAR

typedef struct s_node
{
	int				value;
	int				index;
	int				curr_pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_extract
{
	int			number;
	int			start;
	int			end;
	char		*substr;
}	t_extract;

// calculate costs
int		calc_cost(int size, int pos);
void	update_costs(t_node *a, t_node *b);
int		set_cheapest(t_node *stack_b);

// ft_split
char	**ft_split(char *str);

// index handling
void	create_index(t_node *stack);
void	update_curr_pos(t_node *stack);

// main
int		main(int argc, char **argv);
void	push_swap(t_node **stack_a, t_node **stack_b);
// int		manage_two_args(char **argv, t_node **stack_a);
int		take_actions(t_node **stack_a, t_node **stack_b);

// movements
void	rotate_pos(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b);
void	rotate_neg(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b);
void	rotate_a_alone(t_node **stack_a, int cost_a);
void	execute_move(t_node **stack_a, t_node **stack_b, int index);

// push
void	push_a(t_node **stack_b, t_node **stack_a);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rotate_a_alone(t_node **stack_b, int cost_b);

// rev rotate
void	rev_rotate_a(t_node **stack_a);
void	rev_rotate_b(t_node **stack_b);
void	rrr_rotate(t_node **stack_a, t_node **stack_b);

// rotate
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rr_rotate(t_node **stack_a, t_node **stack_b);

// sorting
void	init_nodes(t_node *stack_a, t_node *stack_b);
void	sort_3(t_node **stack_a);
void	sort_5(t_node **stack_a, t_node **stack_b);
void	sort_all(t_node **stack_a, t_node **stack_b);

// stack_a creation
t_node	*create_new_node(void);
t_node	*get_last_node(t_node *stack);
int		args_to_stack(char **numbers, t_node **stack);

// stack_b operations
int		count_nodes(t_node *stack);
void	create_stack_b(t_node **stack_a, t_node **stack_b);
void	set_target_pos(t_node *stack_a, t_node *stack_b);

// swap
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	ss_swap(t_node **stack_a, t_node **stack_b);

// utils
int		is_space(char c);
long	ft_atol(const char *str);
void	free_stack(t_node **stack);
void	free_split(char **arr);
int		neg_to_abs(int a);
void	print_stack_state(const char *name, t_node *stack); // BORRAR

// verification checks
int		not_duplicated(t_node *stack, int number);
int		is_numeric(char *str);
int		is_int(long number);
int		is_sorted(t_node *stack);
void	free_and_write(t_node **stack);

#endif
