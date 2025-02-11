/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:17:29 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/07 09:43:31 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

// void	*ft_empty_array(char **array, size_t words)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < words)
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (NULL);
// }

// size_t	ft_count_words(char *buffer, char c)
// {
// 	size_t	i;
// 	size_t	words;

// 	i = 0;
// 	words = 0;
// 	while (buffer[i] != '\0')
// 	{
// 		if (buffer[i] == c)
// 			i++;
// 		else
// 		{
// 			words++;
// 			while (buffer[i] != c && buffer[i] != '\0')
// 				i++;
// 		}
// 	}
// 	return (words);
// }

// void	ft_fill_array(char *array, char *buffer, size_t start, size_t end)
// {
// 	size_t	i;

// 	i = 0;
// 	while (start < end)
// 	{
// 		array[i] = buffer[start];
// 		start++;
// 		i++;
// 	}
// 	array[i] = '\0';
// }

// char	**ft_split_continuo(char *str, char **array, char c, int end)
// {
// 	size_t	i;
// 	size_t	start;

// 	i = 0;
// 	array = malloc((ft_count_words(str, c) + 1) * sizeof(char *));
// 	if (array == NULL)
// 		return (NULL);
// 	while (str[end] != '\0')
// 	{
// 		if (str[end] == c)
// 			end++;
// 		else
// 		{
// 			start = end;
// 			while (str[end] != c && str[end] != '\0')
// 				end++;
// 			array[i] = malloc((end - start + 1) * sizeof(char));
// 			if (array[i] == NULL)
// 				return (ft_empty_array(array, i));
// 			ft_fill_array(array[i], str, start, end);
// 			i++;
// 		}
// 	}
// 	array[i] = NULL;
// 	return (array);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	*str;
// 	char	**array;
// 	size_t	end;

// 	if (s == NULL)
// 		return (NULL);
// 	end = 0;
// 	str = (char *)s;
// 	array = NULL;
// 	return (ft_split_continuo(str, array, c, end));
// }