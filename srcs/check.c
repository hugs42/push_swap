/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:21:14 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/03 19:12:05 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	ft_check_max(int nb)
{
	int	min;
	int	max;

	min = -2147483648;
	max = 2147483647;
	if (nb > max)
		return (ERROR);
	if (nb < min)
		return (ERROR);
	return (SUCCESS);
}

int	ft_check_len(char *input, char c)
{
	int			i;
	int			is_char;
	size_t		len;

	i = 0;
	len = 0;
	is_char = 1;
	while (input[i])
	{
		if (input[i] != c && is_char)
		{
			len++;
			is_char = 0;
		}
		if (input[i] == c)
			is_char = 1;
		if (len == 0)
			return (ERROR);
		i++;
	}
	return (len);
}

int	ft_check_char(char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if ((input[i] < 48 || input[i] > 57) && input[i] != '-')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_check_double(int *input, int len, int nb)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (input[i] == nb)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
