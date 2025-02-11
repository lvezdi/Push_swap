/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:55:22 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/01/20 12:17:14 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int is_nums(char *str)
// {
// 	int nums;
// 	int i;

// 	i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ') 
// 		i++;
// 	while ((i > 0 && str[i - 1] == ' ' && str[i] == '-' ) && )
// 	if (i < ft_strlen(str) - 1)
// 		return  (0);
// 	else
// 		return (1);
	
// }

int num(char *str)
{
	char **nums;
	int i;
	int	j;

	i = 0;
	nums = ft_split(str, ' ');
	while (nums[i] != NULL)
	{
		j = 0;
		if (nums[i][j] == '-')
		{
			if (nums[i][j + 1] >= '0' && nums[i][j + 1] <= '9')
				j++;
			else
			{
				ft_empty_array(nums);
				return (0);
			}
		}
		while (nums[i][j] >= '0' && nums[i][j] <= '9')
			j++;
		if (j < ft_strlen(nums[i]) - 1)
		{
			ft_empty_array(nums);
			return (0);
		}
		i++;
	}
	return (1);
}

// int main(int argc, char **argv)
// {
// 	int i;
// 	char res;

// 	res = ft_parceo(ac, av);
// 	i = 1;
// 	if (argc > i)
// 	{
// 		while (res[i])
// 		i++;
// 	}
// }

#include "push_swap.h"

// int	ft_atoi(const char *str)
// {
// 	int		sign;
// 	int		result;
// 	int		i;

// 	sign = 1;
// 	result = 0;
// 	i = 0;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (sign * result);
// }

void	*ft_empty_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

int is_in_range_of_int(char *next_n)
{
    size_t  len;
    int     max_common;
    char    *ch_number;
    int     sign;
	
    len = ft_strlen(next_n) - 1;
    sign = next_n[0] == '-';
    max_common = 214748364;
    if (len + 1 > 11 || (len + 1 == 11 && !sign))
        return (0);
    else if (len + 1 < 10)
        return (1);
    if (next_n[0] == '-')
    {
        next_n++;
        len--;
    }
    ch_number = ft_substr(next_n, 0, len);
    if (ft_atoi(ch_number) > max_common)
        return (free(ch_number), 0);
	else if (ft_atoi(ch_number) < max_common)
		return (free(ch_number), 1);
    else if ((sign && next_n[len] > '8') || (!sign && next_n[len] > '7'))
        return (free(ch_number), 0);
    else
        return (free(ch_number), 1);
}

// int	main(void)
// {
// 	printf("is ins range of int: %d\n", is_in_range_of_int("1147483649"));
// }