/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:42:21 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/27 17:04:21 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 'a', 0);
	swap(stack_b, 'b', 0);
	write(1, "ss\n", 3);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	ops_rotate(stack_a, 'a', 0);
	ops_rotate(stack_b, 'b', 0);
	write(1, "rr\n", 3);
}

void	ops_reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	ops_reverse_rotate(stack_a, 'a', 0);
	ops_reverse_rotate(stack_b, 'b', 0);
	write(1, "rrr\n", 4);
}
