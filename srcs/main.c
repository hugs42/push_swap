/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:43:01 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/02 13:20:39 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ft_show_stack(t_data *data, int stack)
{
	int i;
	int	stack_nb;

	i = 0;
	if (stack == 1)
	{
		while (data->a[i])
		{
			ft_putnbr_fd(data->a[i], 1);
			ft_putchar_fd(' ', 1 );
			i++;
		}
	}
	else if (stack == 2)
	{
		while (data->b[i])
		{
			ft_putnbr_fd(data->b[i], 1);
			ft_putchar_fd(' ', 1 );
			i++;
		}
	}
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

int		ft_free_input(char **input)
{
	int		i;

	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
	return (SUCCESS);
}

int		ft_already_sort_a(t_data *data, int len)
{
	int		i;

	i = 0;
	i = data->a_first - len + 1;
	while (i < data->a_first)
	{
		if (data->a[i] < data->a[i + 1])
			return (0);
		i++;
	}
//;	ft_putstr_fd("a already sort\n", 1);
	return (SUCCESS);
}

int		ft_already_sort_b(t_data *data, int len)
{
	int		i;

	i = 0;
	i = data->b_first - len + 1;
	while (i < data->b_first)
	{
		if (data->b[i] < data->b[i + 1])
			return (0);
		i++;
	}
//	ft_putstr_fd("b already sort\n", 1);
	return (SUCCESS);
}

int		ft_sort_5_arg(t_data *data)
{
	
	return (SUCCESS);
}

int		ft_sort_3_arg(t_data *data)
{
	if (data->a[2] > data->a[1])
		ft_sa(data, 1);
	if (data->a[0] < data->a[1])
	{
//		ft_putstr_fd("OKKK", 1);
		ft_rra(data, 1);
		if (data->a[1] < data->a[2])
			ft_sa(data, 1);
	}
	return (SUCCESS);
}

int		ft_sorting(t_data *data, int len)
{
	if (len == 3)
	{
//		ft_putstr_fd("\nlen = 3\n", 1);
		ft_sort_3_arg(data);
	}
	else if (len == 5)
	{
//		ft_putstr_fd("\nlen = 5\n", 1);
//		ft_sort_5_arg(data);
	}
	return (SUCCESS);
}

int		ft_push_swap(int argc, char **argv)
{
	int		i;
	int		len;
	char	*input;
	t_data	data;

	if (ft_parse_input(&data, argc, argv) == ERROR)
	{
		ft_putstr_fd("ERROR\n", 1);
		exit (0);
	}
	if (ft_already_sort_a(&data, data.len) == SUCCESS)
		exit(0);
	else
		ft_sorting(&data, data.len);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr_fd("Error\n", 1);
	else
	{
		if (ft_push_swap(argc, argv) == ERROR)
			ft_putstr_fd("Error\n", 1);
	}
	return (0);
}
