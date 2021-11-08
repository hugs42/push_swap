/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:43:01 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/08 10:44:01 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

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
	ft_exit(&data);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		ft_push_swap(argc, argv);
	return (0);
}
