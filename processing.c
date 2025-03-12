/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:14:31 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/10 16:21:49 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*process_arguments(int argc, char **argv)
{
	int		i;
	char	*combined_args;

	i = 1;
	combined_args = ft_calloc(1, sizeof(char));
	if (!combined_args)
		return (NULL);
	while (i < argc)
	{
		if (argv[i][0] == '\0' || is_only_spaces(argv[i]))
		{
			free(combined_args);
			error();
		}
		combined_args = join_with_space(combined_args, argv[i]);
		if (!combined_args)
		{
			free(combined_args);
			return (NULL);
		}
		i++;
	}
	return (combined_args);
}

void	process_nums(char **nums, int count)
{
	int	i;

	i = 0;
	check_string(nums, count);
	check_duplicates(nums, count);
	while (nums[i] != NULL)
	{
		if (numeric(nums[i], nums, count) == -1)
		{
			ft_empty_array(nums, count);
			error();
		}
		i++;
	}
	if (ft_is_sorted(nums, count))
	{
		ft_empty_array(nums, count);
		exit(0);
	}
}
