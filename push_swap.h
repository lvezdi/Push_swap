/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:58:19 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/12/19 12:54:45 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void			swap(t_stack *stack, char n);
void			rotate(t_stack *stack, char n);
void			riverse(t_stack *stack, char n);
void			push(t_stack *stack, char n);
void			new_stack(t_stack *stack);
void			delete_node(t_stack *stack);
int				main(int argc, char **argv);
int				ft_atoi(const char *str);
static void		*ft_empty_array(char **array, size_t words);
static size_t	ft_count_words(char *buffer, char c);
static void		ft_fill_array(char *array, char *buffer,
					size_t start, size_t end);
static char		**ft_split_continuo(char *str, char **array, 
					char c, int end);
char			**ft_split(char const *s, char c);
#endif