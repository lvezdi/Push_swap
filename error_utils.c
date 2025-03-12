/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:59:13 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/10 13:05:20 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	print_str("Error\n");
	exit(1);
	return (1);
}

int	print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write (2, "(null)", 6));
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	return (i);
}
