/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:14:31 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/07 13:24:17 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*process_arguments(int argc, char **argv)
{
	int		i;
	char	*cadena;

	i = 1;
	cadena = ft_calloc(1, sizeof(char));
	if (!cadena)
		return (NULL);
	while (i < argc)
	{
		if (argv[i][0] == '\0' || is_only_spaces(argv[i]))
		{
			free(cadena);
			error();
		}
		cadena = join_space(cadena, argv[i]);
		if (!cadena)
			return (free(cadena), NULL);
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
