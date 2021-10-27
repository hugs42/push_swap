/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:43:01 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/27 16:24:18 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	ft_show_stack(t_data *data)
{
	int i;

	i = 0;
	while (data->a[i])
	{
		ft_putnbr_fd(data->a[i], 1);
		ft_putchar_fd(' ', 1 );
		i++;
	}
}

void	ft_swap_stack(t_data *data)
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
		ft_putstr_fd("ERROR\n", 1);
		exit (0);
	}
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
