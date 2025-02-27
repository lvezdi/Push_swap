/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:14:31 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/27 18:25:01 by lvez-dia         ###   ########.fr       */
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

t_node	*ft_create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = value;
	node->next = NULL;
	return (node);
}

