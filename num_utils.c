/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:57:55 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/10 15:25:34 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numeric(char *str, char **nums, int count)
{
	size_t	i;

	i = 0;
	if ((str[i] == '-' && (str[i + 1] != '\0'))
		|| (str[i] == '+' && (str[i + 1] != '\0')))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_empty_array(nums, count);
			error();
		}
		i++;
	}
	return (1);
}

int	ft_new_atoi(const char *str, char **nums, int count)
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
	result = ft_atoi_int(result, nums, count);
	return (result);
}

int	ft_atoi_int(long result, char **nums, int count)
{
	if (result < INT32_MIN || result > INT32_MAX)
	{
		ft_empty_array(nums, count);
		error();
	}
	return ((int) result);
}

int	ft_is_sorted(char **nums, int count)
{
	int	i;
	int	num1;
	int	num2;
	int	cnt;

	cnt = 0;
	while (nums[cnt] != NULL)
		cnt++;
	i = 0;
	while (i < (cnt - 1))
	{
		num1 = ft_new_atoi(nums[i], nums, count);
		num2 = ft_new_atoi(nums[i + 1], nums, count);
		if (num1 > num2)
			return (0);
		i++;
	}
	return (1);
}
