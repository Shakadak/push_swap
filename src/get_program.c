/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:13:08 by npineau           #+#    #+#             */
/*   Updated: 2017/11/30 10:54:36 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"

t_str	get_operation(t_str name)
{
	static char	ops[11][2][4] = {
		{"sa", "sa"},
		{"sb", "sb"},
		{"ss", "ss"},
		{"pa", "pa"},
		{"pb", "pb"},
		{"ra", "ra"},
		{"rb", "rb"},
		{"rr", "rr"},
		{"rra", "rra"},
		{"rrb", "rrb"},
		{"rrr", "rrr"}
	};
	size_t		i;

	i = 0;
	while (i < 11)
	{
		if (ft_strequ(name, ops[i][0]))
		{
			return (ops[i][1]);
		}
		i += 1;
	}
	return (NULL);
}

int	get_program(t_rb *instructions)
{
	int		check;
	t_str	buff;
	t_str	op;

	buff = NULL;
	while ((check = get_next_line(STDIN_FILENO, &buff)) > 0)
	{
		op = get_operation(buff);
		free(buff);
		if (op == NULL)
		{
			return (0);
		}
		else
		{
			rb_grow_push_back(instructions, op);
		}
	}
	return (check != -1);
}
