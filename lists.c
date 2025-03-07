/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:59:37 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/07 13:25:17 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

void	init_stack(t_stack *stack, int *num, int count)
{
	int	i;

	i = 0;
	i = count - 1;
	while (i >= 0)
	{
		lst_add(stack, num[i], 0);
		i--;
	}
}

void	lst_add(t_stack *stack, int data, int index)
{
	t_node	*node;

	node = ft_create_node(data, index);
	node->next = stack->head;
	stack->head = node;
	stack->size++;
}

t_node	*ft_create_node(int data, int index)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->s_index = index;
	node->next = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}
	free(stack);
}
