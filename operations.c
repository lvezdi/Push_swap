/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:14:47 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/10 16:04:39 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char n)
{
	t_node	*temp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
	write(1, "s", 1);
	write(1, &n, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *stack, char n)
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
	write(1, "r", 1);
	write(1, &n, 1);
	write(1, "\n", 1);
}

void	reverse(t_stack *stack, char n)
{
	t_node	*temp;
	t_node	*final;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	final = stack->head;
	while (final->next->next != NULL)
		final = final->next;
	temp = final->next;
	final->next = NULL;
	temp->next = stack->head;
	stack->head = temp;
	write(1, "rr", 2);
	write(1, &n, 1);
	write(1, "\n", 1);
}

void	push(t_stack *from_stack, t_stack *to_stack, char n)
{
	int	index;
	int	data;

	if (from_stack->head == NULL)
		return ;
	index = from_stack->head->s_index;
	data = del_stack(from_stack);
	add_node_to_stack(to_stack, data, index);
	write(1, "p", 1);
	write(1, &n, 1);
	write(1, "\n", 1);
}
