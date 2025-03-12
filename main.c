/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:24:33 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/10 16:11:52 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_and_validate_numbers(int argc, char **argv, int *count)
{
	char	**nums;
	int		*numbers;
	char	*num1;

	*count = 0;
	if (argc < 2)
		return (0);
	num1 = process_arguments(argc, argv);
	nums = ft_split(num1, ' ');
	free (num1);
	if (!nums)
		return (NULL);
	while (nums[*count] != NULL)
		(*count)++;
	process_nums(nums, *count);
	numbers = convert_to_number(nums, *count);
	ft_empty_array(nums, *count);
	return (numbers);
}

int	*convert_to_number(char **nums, int count)
{
	int	i;
	int	*numbers;

	i = 0;
	numbers = (int *)malloc(count * sizeof(int));
	if (!numbers)
		return (NULL);
	while (i < count)
	{
		numbers[i] = ft_new_atoi(nums[i], nums, count);
		i++;
	}
	return (numbers);
}

t_stack	*process_stack(int *numbers, int count)
{
	t_stack	*stack_a;

	stack_a = ft_create_stack();
	if (!stack_a)
		return (NULL);
	initialize_stack(stack_a, numbers, count);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;

	numbers = parse_and_validate_numbers(argc, argv, &count);
	if (!numbers)
		return (1);
	stack_a = process_stack(numbers, count);
	stack_b = ft_create_stack();
	assign_index(stack_a, numbers, count);
	sort(stack_a, stack_b, count);
	free_stack(stack_a);
	free_stack(stack_b);
	free(numbers);
	return (0);
}
