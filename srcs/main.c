/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:43:01 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/08 09:56:15 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

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

int	ft_push_swap(int argc, char **argv)
{
	t_data	data;

	if (ft_parse_input(&data, argc, argv) == ERROR)
	{
		ft_putstr_fd("Error\n", 1);
		ft_exit(&data);
	}
	if (ft_already_sort_a(&data, data.len) == SUCCESS)
		ft_exit(&data);
	else
		ft_sorting(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (ft_push_swap(argc, argv) == ERROR)
			ft_putstr_fd("Error\n", 1);
//		while (1)
		{

		}
	}
	return (0);
}
