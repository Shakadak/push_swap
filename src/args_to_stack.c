/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:23:27 by npineau           #+#    #+#             */
/*   Updated: 2017/11/28 10:02:32 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/push_swap.h"

int	args_to_stack(size_t n, t_string *args, t_rb *a)
{
	int			x;
	size_t		i;
	t_string	leftover;

	i = 0;
	leftover = NULL;
	while (i < n)
	{
		if (parse_int(args[i], &leftover, &x) && ft_strempty(leftover))
		{
			rb_grow_push_back(a, &x);
		}
		else
		{
			free(leftover);
			return (0);
		}
		free(leftover);
		leftover = NULL;
		i += 1;
	}
	return (1);
}
