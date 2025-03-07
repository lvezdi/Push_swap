/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:38:12 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/07 13:25:40 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->s_index <= i)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else if (stack_a->head->s_index <= i + range)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a');
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	while (length--)
	{
		if (count_index(stack_b->head, length) <= stack_b->size / 2)
		{
			while (stack_b->head->s_index != length)
				rotate(stack_b, 'b');
		}
		else
		{
			while (stack_b->head->s_index != length)
				reverse(stack_b, 'b');
		}
		push(stack_b, stack_a, 'a');
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	if (is_stack_sorted(stack_a))
	{
		free_stack(stack_a);
		error();
	}
	if (length == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
			swap(stack_a, 'a');
	}
	else if (length == 3)
		simple_sort(stack_a, length);
	else if (length <= 7)
		s_insertion_sort(stack_a, stack_b, length);
	else if (length > 7)
	{
		k_sort1(stack_a, stack_b, length);
		k_sort2(stack_a, stack_b, length);
	}
	else
		error();
}

int	del_stack(t_stack *stack)
{
	t_node	*first;
	int		data;

	if (!stack->head)
		exit (1);
	first = stack->head;
	data = first->data;
	stack->head = first->next;
	free(first);
	first = NULL;
	stack->size--;
	return (data);
}
