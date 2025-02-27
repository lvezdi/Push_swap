/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:14:47 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/27 17:13:20 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char n, int b)
{
	t_node	*temp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	temp = stack->head;
	stack->head = stack->head->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
	if (b == 1)
	{
		write(1, "s", 1);
		write(1, &n, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack *stack, char n, int b)
{
	t_node	*temp;
	t_node	*final;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	final = stack->head;
	while (final->next != NULL)
		final = final->next;
	final->next = temp;
	temp->next = NULL;
	if (b == 1)
	{
		write(1, "r", 1);
		write(1, &n, 1);
		write(1, "\n", 1);
	}
}

void	riverse(t_stack *stack, char n, int b)
{
	t_node	*temp;
	t_node	*final;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	temp = stack->head;
	final = stack->head;
	while (final->next != NULL)
		final = final->next;
	temp = final->next;
	final->next = NULL;
	temp->next = stack->head;
	stack->head = temp;
	if (b == 1)
	{
		write(1, "rr", 1);
		write(1, &n, 1);
		write(1, "\n", 1);
	}
}

void	push(t_stack *from_stack, t_stack *to_stack, char n, int b)
{
	t_node	*temp;

	if (from_stack->head == NULL)
		return ;
	temp = from_stack->head;
	from_stack->head = temp->next;
	temp->next = to_stack->head;
	to_stack->head = temp;
	from_stack->size--;
	to_stack->size++;
	if (b == 1)
	{
		write(1, "p", 1);
		write(1, &n, 1);
		write(1, "\n", 1);
	}
}
