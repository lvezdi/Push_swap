/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:24:33 by lvez-dia          #+#    #+#             */
/*   Updated: 2025/02/11 09:42:44 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

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

int	print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write (1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	error(void)
{
	print_str("Error\n");
	return (1);
}

char	*join_space(char const *s1, char const *s2, char *str)
{
	int	i;
	int	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 2), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = ' ';
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free((void *)s1);
	return (str);
}

void	check_string(char **nums)
{
	int	i;

	i = 0;
	while (nums[i] != NULL)
	{
		if (is_only_spaces(nums[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}


// int	check_string(char **nums)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (nums[j] != NULL)
// 	{
// 		while (nums[i] != NULL)
// 		{
// 			if (nums[j][i] != ' ')
// 			{
// 				break ;
// 			}
// 			else if (nums[j][i] == ' ')
// 				exit (1);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (0);
// }

void	compare(char **nums)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (nums[i])
	{
		num1 = ft_atoi(nums[i]);
		j = i + 1;
		while (nums[j])
		{
			num2 = ft_atoi(nums[j]);
			if (num1 == num2)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return ;
}

int	numeric(char *str)
{
	size_t	i;

	i = 0;
	if ((str[i] == '-' && (str[i + 1] != '\0')) || (str[i] == '+' && (str[i + 1] != '\0')))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
	return (1);
}

int non_numeric(char *str)
{
	if (!numeric(str))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*cadena;
	char	**nums;
	int		number;

	if (argc <= 2)
		return (1);
	cadena = ft_calloc(1, sizeof(char));
	if (!cadena)
		return (1);
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][j] == '\0' || is_only_spaces(argv[i]))
		{
			free(cadena);
			write(1, "Error\n", 6);
			return (1);
		}
		cadena = join_space(cadena, argv[i], cadena);
		i++;
	}
	nums = ft_split(cadena, ' ');
	if (!nums)
		return (1);
	check_string(nums);
	compare(nums);
	i = 0;
	while (nums[i] != NULL)
	{
		if (numeric(nums[i]) == -1)
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		i++;
	}
	i = 0;
	while (nums[i] != NULL)
	{
		number = ft_atoi(nums[i]);
		if (number > INT32_MAX || number < INT32_MIN)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		printf("Number %d: %d\n", i + 1, number);
		i++;
	}
	free(cadena);
	ft_empty_array(nums, i);
	return (0);
}


/*int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*cadena;
	char	**nums;
	int		number;

	if (argc <= 2)
		return (1);
	cadena = ft_calloc(1, sizeof(char));
	if (!cadena)
		return (1);
	i = 1;
	j = 0;
	while (i < argc)
	{
		while (isspace(argv[i][j]) && argv[i][j] != '\0')
		{
			if (argv[i][j] == '\0' || (argv[i][j] == 32 && argv[i][j + 1] == '\0'))
			{
				free(cadena);
				write(1, "Error\n", 7);
				return (1);
			}
			j++;
		}
		if (argv[i][0] == '\0' || (argv[i][0] == 32 && argv[i][1] == '\0'))
		{
			free(cadena);
			write(1, "Error\n", 7);
			return (1);
		}
		cadena = join_space(cadena, argv[i], cadena);
		i++;
	}
	nums = ft_split(cadena, ' ');
	if (!nums)
		return (1);
	compare(nums);
	check_string(nums);
	i = 0;
	while (nums[i] != NULL)
	{
		if (numeric(nums[i]) == -1)
		{
			write(1, "Error\n", 7);
			exit (1);
		}
		i++;
	}
	i = 0;
	while (nums[i] != NULL)
	{
		number = ft_atoi(nums[i]);
		if (number > INT32_MAX || number < INT32_MIN)
			return (1);
		printf("Number %d: %d\n", i + 1, number);
		i++;
	}
	free(cadena);
	ft_empty_array(nums, i);
	return (0);
}*/





/*
1º join_space = que el join de la libft pero en la reserva de memoria se hace +2 poque se necesita guardar u espacio para el ' ' y otro para el '\0'
despues de la copia ponerselo
hacer un control sel s1 en caso de que no exita un s2

2º compare en el que si av[i] av[j] = 0, la j = i + 1 para eel comparando si los numeros son iguales

3º Meterlo con el doble puntero en atoi para que sean enteros 

4º check num , espacios y signos 

5 º "funcion principal"(argc y argv) en el que primero se haga el join_space posteriormente el split y por último check nums


atoi a cada split? pasar i de cada split?
oque pasa con lo de que no sea mas grande que el maximo de enteros y el minimo de enteros?
 0006 09 ????
45 -8 "-34+56-2"???
itoa?


Paso 1: Combina los argumentos.

Paso 2: Verifica duplicados.

Paso 3: Divide la cadena combinada.

Paso 4: Convierte los números a enteros.*/


// no me sale salida por error al tener duplicado: ./prueba "3 2 1 2"
// no me sale Salida con error debido a caracteres no numéricos: ./prueba "3 a 1" 
/* #!/bin/bash

# Test cases
tests=(
    "./prueba"                     # Espera: nueva línea
	
    "./prueba \"42\""              # Espera: Number 1: 42
    "./prueba \"3 2 1\""           # Espera: Number 1: 3, Number 2: 2, Number 3: 1
    "./prueba \"-3 -2 -1\""        # Espera: Number 1: -3, Number 2: -2, Number 3: -1
    "./prueba \"3 -2 1 -4\""       # Espera: Number 1: 3, Number 2: -2, Number 3: 1, Number 4: -4
    "./prueba \"3 2 1 2\""         # Espera: Salida con error debido a duplicados
    "./prueba \"2147483647 -2147483648\"" # Espera: Number 1: 2147483647, Number 2: -2147483648
    "./prueba \"3 a 1\""           # Espera: Salida con error debido a caracteres no numéricos
    "./prueba \"3    2  1\""       # Espera: Number 1: 3, Number 2: 2, Number 3: 1
    "./prueba \"- 3 2 - -1\""      # Espera: Salida con error debido a signos incorrectos
    "./prueba \"3 2\" \"1 -4\" \"5 -6\"" # Espera: Number 1: 3, Number 2: 2, Number 3: 1, Number 4: -4, Number 5: 5, Number 6: -6
)

# Expected results
expected=(
    "$"
    "Number 1: 42"
    "Number 1: 3\nNumber 2: 2\nNumber 3: 1"
    "Number 1: -3\nNumber 2: -2\nNumber 3: -1"
    "Number 1: 3\nNumber 2: -2\nNumber 3: 1\nNumber 4: -4"
    "Error: Duplicated numbers"
    "Number 1: 2147483647\nNumber 2: -2147483648"
    "Error: Non-numeric character"
    "Number 1: 3\nNumber 2: 2\nNumber 3: 1"
    "Error: Incorrect signs"
    "Number 1: 3\nNumber 2: 2\nNumber 3: 1\nNumber 4: -4\nNumber 5: 5\nNumber 6: -6"
)

# Run tests
for index in "${!tests[@]}"; do
    output=$(eval ${tests[$index]} | cat -e)
    echo -e "Ran: ${tests[$index]}\nExpected: ${expected[$index]}\nOutput: $output"
    echo "-----------------------------------------"
done
*/


/*
./prueba  1 a 
Number 1: 1

./prueba 2 749 " "
Number 1: 2
Number 2: 749

./prueba "12" a2
Number 1: 12




1. No imprime error: ./prueba "1 3 00001" NO ENTIENDO EL LLDB
2. no me aparece nada: ./prueba "1 3 000000000000000000000000000000000002"
3. y por qué con este si?: ./prueba 83 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000075
Number 1: 83
Number 2: 75
ES PORQUE ESTA DENRO DEL STRING, FUERA SI QUE LO HACE
4. Gestionar si ya viene ordenado: ./prueba 1 2 3  
*/