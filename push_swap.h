/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:58:19 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/07 13:42:46 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>

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

//movimientos
void			swap(t_stack *stack, char n);
void			rotate(t_stack *stack, char n);
void			reverse(t_stack *stack, char n);
void			push(t_stack *from_stack, t_stack *to_stack, char n);

//char_utils
int				is_only_spaces(char *str);
char			*join_space(char *s1, const char *s2);
void			check_string(char **nums);
void			compare(char **nums);

//error_utils
int				error(void);
int				print_str(char *s);

//num_utils
int				numeric(char *str);
int				non_numeric(char *str);
int				ft_is_sorted(char **nums);
int				ft_new_atoi(const char *str);

//process
char			*process_arguments(int argc, char **argv);
void			process_nums(char **nums);

//lists
t_stack			*ft_create_stack(void);
void			init_stack(t_stack *stack, int *numbers, int count);
void			lst_add(t_stack *stack, int value, int index);
t_node			*ft_create_node(int value, int index);
void			free_stack(t_stack *stack);
// void			push_stack(t_stack *stack, int index, int data);
// int				del_stack(t_stack *stack);

//index / others
void			ft_bubblesort(int *array, int count);
int				find_min_index(t_stack *stack);
int				ft_index(int n, int *array);
void			asigne_index(t_stack *stack_a, int *numbers, int count);
int				count_index(t_node *stack, int index);

//algoritmo
int				ft_sqrt(int number);
void			k_sort1(t_stack *stack_a, t_stack *stack_b, int length);
void			k_sort2(t_stack *stack_a, t_stack *stack_b, int length);
void			sort(t_stack *stack_a, t_stack *stack_b, int length);

//sort
int				is_rot_sort(t_stack *stack);
int				is_stack_sorted(t_stack *stack);
void			simple_sort(t_stack *stack, int length);
void			s_insertion_sort(t_stack *stack_a, t_stack *stack_b,
					int length);

//main
int				*process_numbers(int argc, char **argv, int *count);
int				*process_and_convert(char **nums, int count);
t_stack			*process_stack(int *numbers, int count);

//void			print_stack(t_stack *stack);
int				del_stack(t_stack *stack);
#endif