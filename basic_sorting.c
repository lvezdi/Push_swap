/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:01:12 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/12 10:33:20 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rot_sort(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->head || !stack->head->next)
		return (1);
	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	simple_sort(t_stack *stack, int length)
{
	int	min_s_index;
	int	c;

	if (is_stack_sorted(stack))
		return ;
	min_s_index = find_min_index(stack);
	c = count_index(stack->head, min_s_index);
	if (is_rot_sort(stack))
	{
		if (c < length - c)
			rotate(stack, 'a');
		else
			reverse(stack, 'a');
	}
	else
	{
		swap(stack, 'a');
		if (is_stack_sorted(stack))
			return ;
		if (c < length - c)
			rotate(stack, 'a');
		else
			reverse(stack, 'a');
	}
}

void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	min_index;
	int	remaining;

	remaining = length - 3;
	while (remaining--)
	{
		min_index = find_min_index(stack_a);
		while (stack_a->head->s_index != min_index)
		{
			if (count_index(stack_a->head, min_index) <= stack_a->size / 2)
				rotate(stack_a, 'a');
			else
				reverse(stack_a, 'a');
		}
		push(stack_a, stack_b, 'b');
	}
	simple_sort(stack_a, 3);
	while (stack_b->size > 0)
		push(stack_b, stack_a, 'a');
}
