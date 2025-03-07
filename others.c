/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:08:02 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/07 13:24:54 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubblesort(int *array, int count)
{
	int	i;
	int	flag;
	int	temp;

	i = 0;
	if (!array || count <= 1)
		return ;
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < count - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				flag = 1;
			}
			i++;
		}
		count--;
	}
}

int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_index;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	min_index = current->s_index;
	while (current)
	{
		if (current->s_index < min_index)
			min_index = current->s_index;
		current = current->next;
	}
	return (min_index);
}

int	ft_index(int n, int *array)
{
	int	i;

	i = 0;
	while (array[i] != n)
		i++;
	return (i);
}

void	asigne_index(t_stack *stack_a, int *numbers, int count)
{
	t_node	*temp;

	ft_bubblesort(numbers, count);
	temp = stack_a->head;
	while (temp)
	{
		temp->s_index = ft_index(temp->data, numbers);
		temp = temp->next;
	}
}

int	count_index(t_node *stack, int index)
{
	int	counter;

	if (!stack)
		return (-1);
	counter = 0;
	while (stack)
	{
		if (stack->s_index == index)
			return (counter);
		stack = stack->next;
		counter++;
	}
	return (0);
}
