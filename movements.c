/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:14:47 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/25 16:07:14 by lvez-dia         ###   ########.fr       */
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
	//if (1 o 2)
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
	final = stack->head;
	while (final->next != NULL)
		final = final->next;
	stack->head = temp->next;
	final->next = temp;
	temp->next = NULL;
	write(1, "r", 1);
	write(1, &n, 1);
	write(1, "\n", 1);
}

void	riverse(t_stack *stack, char n)
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
	write(1, "rr", 1);
	write(1, &n, 1);
	write(1, "\n", 1);
}

void	push(t_stack *stack, char n)
{
	t_node	*temp;
	t_node	*final;

	if (stack->head != NULL || stack->head->next != NULL)
		return ;
	final = stack->head;
	temp = stack->head->next;
	if (stack->head->next != NULL)
		stack = stack->head->next;
	final->next = NULL;
	temp = final;
	write(1, "p", 1);
	write(1, &n, 1);
	write(1, "\n", 1);
}

// void	new_stack(t_stack *stack, int data, int index)
// {
// 	t_node	*temp;

// 	temp = (t_node *)malloc(sizeof(t_node));
// 	if (!temp)
// 		return ;
// 	temp->data = data;
// 	temp->s_index = index;
// 	temp->next = stack->head;
// 	stack->head = temp;
// 	stack->size++;
// }

// void	delete_node(t_stack *stack)
// {
// 	t_node	*temp; 

// 	temp = (t_node *)malloc(sizeof(t_node));
// 	if (!temp)
// 		return ;
// 	stack->head = temp->next;
// 	temp =  stack->head;
// 	temp = NULL;
	
// }
// stack  1 2 3 N
// temp   2 3 N
// final  1 2 3 N

// 2 3 N
// 1