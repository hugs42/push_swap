/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:21:14 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/10 10:50:38 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ft_check_max(t_data *data, long res)
{
	if (res > 2147483647)
		data->int_limit = 1;
	if (res < -2147483648)
		data->int_limit = 1;
}

int	ft_atoi_limit(t_data *data, const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res *= sign;
	ft_check_max(data, res);
	return ((int)res);
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
