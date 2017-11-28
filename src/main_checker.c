/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:58:41 by npineau           #+#    #+#             */
/*   Updated: 2017/11/28 13:45:27 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include "inc/push_swap.h"

void printnum(void *nbr)
{
	ft_putnbrendl(*(int*)nbr);
}

int	main(int argc, t_string *argv)
{
	t_rb	a;
	t_rb	b;
	t_rb	instructions;

	rb_new(1 /*imax(argc - 1, 16)*/, sizeof(int), &a);
	rb_new(imax(argc - 1, 16), sizeof(int), &b);
	rb_new(16, sizeof(t_string), &instructions);
	if (argc > 1 && !args_to_stack(argc - 1, argv + 1, &a))
	{
		rb_iter(a, printnum);
		return (ft_putendl_fd("Error", STDERR_FILENO));
	}
	rb_iter(a, printnum);
	if (!get_program(&instructions))
	{
		return (ft_putendl_fd("Error", STDERR_FILENO));
	}
	return (0);
}
