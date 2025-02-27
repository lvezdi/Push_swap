/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:24:33 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/27 19:19:48 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*process_numbers(int argc, char **argv, int *count)
{
	int		i;
	char	**nums;
	int		*numbers;

	*count = 0;
	if (argc < 2)
		return (0);
	nums = ft_split(process_arguments(argc, argv), ' ');
	if (!nums)
		return (NULL);
	while (nums[*count] != NULL)
		(*count)++;
	numbers = (int *)malloc(*count * sizeof(int));
	if (!numbers)
	{
		ft_empty_array(nums, *count);
		return (NULL);
	}
	process_nums(nums);
	i = 0;
	while (i < *count)
	{
		numbers[i] = ft_new_atoi(nums[i]);
		printf(" %d: %d\n", i + 1, numbers[i]);
		i++;
	}
	ft_empty_array(nums, *count);
	return (numbers);
}

void	process_stack(t_stack *stack, int *numbers, int count)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (i < count)
	{
		new_node = ft_create_node(numbers[i]);
		if (!new_node)
			return ;
		ft_lstadd_back(&(stack->head), new_node);
		stack->size++;
		i++;
	}
	new_node = stack->head;
	while (new_node)
		new_node = new_node->next;
	while (stack->head)
	{
		new_node = stack->head;
		stack->head = stack->head->next;
		free(new_node);
	}
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		count;
	t_stack	*stack;

	numbers = process_numbers(argc, argv, &count);
	if (!numbers)
		return (1);
	stack = ft_create_stack();
	//list???
	//ft_bubblesort(numbers, *count);
	//while
	if (!stack)
	{
		free(numbers);
		return (1);
	}
	process_stack(stack, numbers, count);
	free(numbers);
	free(stack);
	return (0);
}

/*
1º join_space = que el join de la libft pero en la reserva de memoria 
se hace +2 poque se necesita guardar u espacio para el ' ' y otro para el '\0'
despues de la copia ponerselo hacer un control sel s1 en caso de que no exita 
un s2

2º compare en el que si av[i] av[j] = 0, la j = i + 1 para eel comparando si 
los numeros son iguales

3º Meterlo con el doble puntero en atoi para que sean enteros 

4º check num , espacios y signos 

5 º "funcion principal"(argc y argv) en el que primero se haga el join_space 
posteriormente el split y por último check nums

Paso 1: Combina los argumentos.

Paso 2: Verifica duplicados.

Paso 3: Divide la cadena combinada.

Paso 4: Convierte los números a enteros.*/
