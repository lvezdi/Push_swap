/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:58:19 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:00 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
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

void			swap(t_stack *stack, char n);
void			rotate(t_stack *stack, char n);
void			reverse(t_stack *stack, char n);
void			push(t_stack *from_stack, t_stack *to_stack, char n);

int				is_only_spaces(char *str);
char			*join_with_space(char *s1, const char *s2);
void			check_string(char **nums, int count);
void			check_duplicates(char **nums, int count);

int				error(void);
int				print_str(char *s);

int				numeric(char *str, char **nums, int count);
int				ft_is_sorted(char **nums, int count);
int				ft_new_atoi(const char *str, char **nums, int count);
int				ft_atoi_int(long result, char **nums, int count);

char			*process_arguments(int argc, char **argv);
void			process_nums(char **nums, int count);

t_stack			*ft_create_stack(void);
void			initialize_stack(t_stack *stack, int *numbers, int count);
void			add_node_to_stack(t_stack *stack, int value, int index);
t_node			*ft_create_node(int value, int index);
void			free_stack(t_stack *stack);

void			ft_bubblesort(int *array, int count);
int				find_min_index(t_stack *stack);
int				ft_index(int n, int *array);
void			assign_index(t_stack *stack_a, int *numbers, int count);
int				count_index(t_node *stack, int index);

int				ft_sqrt(int number);
void			k_sort1(t_stack *stack_a, t_stack *stack_b, int length);
void			k_sort2(t_stack *stack_a, t_stack *stack_b, int length);
void			sort(t_stack *stack_a, t_stack *stack_b, int length);
int				del_stack(t_stack *stack);

int				is_rot_sort(t_stack *stack);
int				is_stack_sorted(t_stack *stack);
void			simple_sort(t_stack *stack, int length);
void			s_insertion_sort(t_stack *stack_a, t_stack *stack_b,
					int length);

int				*parse_and_validate_numbers(int argc, char **argv, int *count);
int				*convert_to_number(char **nums, int count);
t_stack			*process_stack(int *numbers, int count);

#endif