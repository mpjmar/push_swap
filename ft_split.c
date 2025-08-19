/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:07:17 by maria-j2          #+#    #+#             */
/*   Updated: 2025/08/14 17:40:22 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static int	count_nbrs(char const *str)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str != '\0')
			words++;
		while (*str && !is_space(*str))
			str++;
	}
	return (words);
}

static char	*nbr_copy(char const *str, int len)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	free_arr(char **arr, int used)
{
	int	i;

	i = 0;
	while (i < used)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**fill_nbrs(char **numbers, const char *arg)
{
	int	i;
	int	len;

	i = 0;
	while (*arg)
	{
		len = 0;
		while (*arg && is_space(*arg))
			arg++;
		if (!*arg)
			break ;
		while (arg[len] && !is_space(arg[len]))
			len++;
		numbers[i] = nbr_copy(arg, len);
		if (!numbers[i])
		{
			free_arr(numbers, i);
			return (NULL);
		}
		i++;
		arg += len;
	}
	numbers[i] = NULL;
	return (numbers);
}

char	**ft_split(char *arg)
{
	char	**numbers;
	int		nbrs;

	if (!arg)
		return (NULL);
	nbrs = count_nbrs(arg);
	numbers = (char **)malloc((nbrs + 1) * sizeof(char *));
	if (!numbers)
		return (NULL);
	numbers = fill_nbrs(numbers, arg);
	return (numbers);
}
