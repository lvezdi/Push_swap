/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:58:19 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/27 18:04:39 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

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

void			swap(t_stack *stack, char n, int b);
void			rotate(t_stack *stack, char n, int b);
void			riverse(t_stack *stack, char n, int b);
void			push(t_stack *from_stack, t_stack *to_stack, char n, int b);
void			swap_both(t_stack *stack_a, t_stack *stack_b);
void			rotate_both(t_stack *stack_a, t_stack *stack_b);
void			ops_reverse_both(t_stack *stack_a, t_stack *stack_b);
int				is_only_spaces(char *str);
int				print_str(char *s);
int				error(void);
char			*join_space(char const *s1, char const *s2, char *str);
void			check_string(char **nums);
int				ft_strcmp(const char *s1, const char *s2);
int				numeric(char *str);
int				num(char *str);
int				non_numeric(char *str);
int				ft_is_sorted(char **nums);
char			*initialize_cadena(void);
char			*process_arguments(int argc, char **argv);
void			process_nums(char **nums);
int				ft_new_atoi(const char *str);
void			compare(char **nums);
t_stack			*ft_create_stack(void);
t_node			*ft_create_node(int value);
int				*process_numbers(int argc, char **argv, int *count);
void			process_stack(t_stack *stack, int *numbers, int count);
void			ft_bubblesort(int *array, int size);
int				index(int n, int *array);

#endif