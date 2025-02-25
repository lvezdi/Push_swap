/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:57:55 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/25 16:02:35 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numeric(char *str)
{
	size_t	i;

	i = 0;
	if ((str[i] == '-' && (str[i + 1] != '\0'))
		|| (str[i] == '+' && (str[i + 1] != '\0')))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			error();
		i++;
	}
	return (1);
}

int	non_numeric(char *str)
{
	if (!numeric(str))
		error();
	return (1);
}

int	ft_new_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = sign * result;
	if (result < INT32_MIN || result > INT32_MAX)
		error();
	return (result);
}

int	ft_is_sorted(char **nums)
{
	int	i;
	int	num1;
	int	num2;
	int	count;

	count = 0;
	while (nums[count] != NULL)
		count++;
	i = 0;
	while (i < (count - 1))
	{
		num1 = ft_new_atoi(nums[i]);
		num2 = ft_new_atoi(nums[i + 1]);
		if (num1 > num2)
			return (0);
		i++;
	}
	return (1);
}

void	ft_bubblesort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (i < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
