/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:58:19 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/07 11:01:53 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./Libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				s_index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

// void			swap(t_stack *stack, char n);
// void			rotate(t_stack *stack, char n);
// void			riverse(t_stack *stack, char n);
// void			push(t_stack *stack, char n);
// void			new_stack(t_stack *stack);
// void			delete_node(t_stack *stack);
// //int				main(int argc, char **argv);
// int				ft_atoi(const char *str);
// int				is_in_range_of_int(char *next_n);
// void			*ft_empty_array(char **array);
// char			*join_space(char const *s1, char const *s2);
// int				num(char *str);
//void			*ft_empty_array(char **array, size_t words);
//size_t			ft_count_words(char *buffer, char c);
//void			ft_fill_array(char *array, char *buffer, size_t start, size_t end);
//char			**ft_split_continuo(char *str, char **array, char c, int end);
//char			**ft_split(char const *s, char c);
//size_t			ft_strlen(const char *s);
//void			*ft_memset(void *b, int c, size_t len);
//void			*ft_calloc(size_t count, size_t size);
char			*join_space(char const *s1, char const *s2, char *str);
int				ft_strcmp(const char *s1, const char *s2);
void			compare(char **nums);
int				num(char *str);
//int				ft_atoi(const char *str);
#endif