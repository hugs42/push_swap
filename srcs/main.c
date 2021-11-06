/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:43:01 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/06 17:29:19 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ft_show_stack(t_data *data, int stack, int len)
{
	int i;
	int	stack_nb;

	i = 0;
	if (stack == 1)
	{
		while (len > 0)
		{
			ft_putnbr_fd(data->a[i], 1);
			ft_putchar_fd(' ', 1 );
			i++;
			len--;
		}
	}
	else if (stack == 2)
	{
		while (len > 0)
		{
			ft_putnbr_fd(data->b[i], 1);
			ft_putchar_fd(' ', 1 );
			i++;
			len--;
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

int		ft_push_swap(int argc, char **argv)
{
	int		i;
	int		len;
	char	*input;
	t_data	data;

	if (ft_parse_input(&data, argc, argv) == ERROR)
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
	if (ft_already_sort_a(&data, data.len) == SUCCESS)
		exit(0);
	else
		ft_sorting(&data);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (ft_push_swap(argc, argv) == ERROR)
			ft_putstr_fd("Error\n", 1);
	}
	return (0);
}
