/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:24:33 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/24 14:02:41 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*initialize_cadena(void)
{
	char	*cadena;

	cadena = ft_calloc(1, sizeof(char));
	if (!cadena)
		return (NULL);
	return (cadena);
}

char	*process_arguments(int argc, char **argv)
{
	int		i;
	int		j;
	char	*cadena;

	i = 1;
	j = 0;
	cadena = initialize_cadena();
	while (i < argc)
	{
		if (argv[i][j] == '\0' || is_only_spaces(argv[i]))
		{
			free(cadena);
			error();
		}
		cadena = join_space(cadena, argv[i], cadena);
		i++;
	}
	return (cadena);
}

void	process_nums(char **nums)
{
	int	i;

	i = 0;
	check_string(nums);
	compare(nums);
	while (nums[i] != NULL)
	{
		if (numeric(nums[i]) == -1)
			error();
		i++;
	}
	if (ft_is_sorted(nums))
		exit (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*cadena;
	char	**nums;
	int		number;
	//t_list 	*stack_a;

	if (argc < 2)
		return (0);
	cadena = process_arguments(argc, argv);
	nums = ft_split(cadena, ' ');
	if (!nums)
		return (1);
	process_nums(nums);
	i = 0;
	while (nums[i] != NULL)
	{
		number = ft_new_atoi(nums[i]);
		printf("Number %d: %d\n", i + 1, number);
		i++;
	}
	free(cadena);
	ft_empty_array(nums, i);
	return (0);
}

// METER NUMEROS AL STACK


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

t_node	*ft_create_node(int	value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = value;
	node->next = NULL;
	return (node);
}

//void	ft_lstadd

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
