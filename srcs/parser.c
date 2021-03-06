/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:14:25 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/16 20:50:40 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	ft_free_input(char **input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
	return (SUCCESS);
}

void	ft_reverse_stack(t_data *data)
{
	int		tmp;
	int		first;
	int		last;

	first = 0;
	last = data->a_first;
	while (first < last)
	{
		tmp = data->a[first];
		data->a[first] = data->a[last];
		data->a[last] = tmp;
		first++;
		last--;
	}
}

int	ft_find_digit(char **input)
{
	int	i;
	int	j;
	int	is_digit;
	int	count_digit;

	i = 1;
	while (input[i])
	{
		j = 0;
		is_digit = 0;
		count_digit = 0;
		while (input[i][j])
		{
			if (input[i][j] >= 48 && input[i][j] <= 57)
			{
				is_digit = 1;
				count_digit++;
			}
			j++;
		}
		if (is_digit == 0 || count_digit > 17)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_check_input(t_data *data, char **input)
{
	int	tmp_i;

	tmp_i = -1;
	while (input[++tmp_i])
	{
		data->a_first += 1;
		if (ft_check_char(input[tmp_i]) == ERROR)
			return (ERROR);
		data->a[data->a_first] = ft_atoi_limit(data, input[tmp_i]);
		if (data->int_limit == 1)
			return (ERROR);
		if (ft_check_double(data->a, data->a_first, data->a[data->a_first])
			== ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_parse_input(t_data *data, int argc, char **argv)
{
	int		i;
	int		len;
	char	**input;

	i = 1;
	len = 0;
	while (i < argc)
		len += ft_check_len(argv[i++], ' ');
	ft_init_data(data, len);
	if (ft_find_digit(argv) == ERROR)
		return (ERROR);
	i = 1;
	while (i < argc)
	{
		input = ft_split(argv[i++], ' ');
		if (ft_check_input(data, input) == ERROR)
		{
			ft_free_input(input);
			return (ERROR);
		}
		ft_free_input(input);
	}
	ft_reverse_stack(data);
	return (SUCCESS);
}
