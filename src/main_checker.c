/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:58:41 by npineau           #+#    #+#             */
/*   Updated: 2017/11/27 15:08:22 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include "inc/push_swap.h"

int	main(int argc, t_string *argv)
{
	t_rb	a;
	t_rb	b;

	rb_new(argc - 1, sizeof(int), &a);
	rb_new(argc - 1, sizeof(int), &b);
	while (argc > 1)
	{
		argc -= 1;
	}
	return (0);
}
