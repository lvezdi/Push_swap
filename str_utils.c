/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:56:39 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/10 16:01:49 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

char	*join_with_space(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 2), sizeof(char));
	if (!str)
		return (free(s1), NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = ' ';
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}

void	check_string(char **nums, int count)
{
	int	i;

	i = 0;
	while (nums[i] != NULL)
	{
		if (is_only_spaces(nums[i]))
		{
			ft_empty_array(nums, count);
			error();
		}
		i++;
	}
}

void	check_duplicates(char **nums, int count)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (nums[i])
	{
		num1 = ft_new_atoi(nums[i], nums, count);
		j = i + 1;
		while (nums[j])
		{
			num2 = ft_new_atoi(nums[j], nums, count);
			if (num1 == num2)
			{
				ft_empty_array(nums, count);
				error();
			}
			j++;
		}
		i++;
	}
	return ;
}
