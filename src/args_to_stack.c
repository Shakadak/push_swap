/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:23:27 by npineau           #+#    #+#             */
/*   Updated: 2017/12/01 09:52:19 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/push_swap.h"

static void	dup_str(t_str const *in, t_str *out, size_t discard)
{
	*out = ft_strdup(*in);
	(void)discard;
}

static int	get_int(t_str str, int *x)
{
	t_str		leftover;
	int			check;

	leftover = NULL;
	check = parse_int(str, &leftover, x) && ft_strempty(leftover);
	free(leftover);
	return (check);
}

static int	int_equ(void *l, void *r)
{
	return (*(int*)l == *(int*)r);
}

int	args_to_stack(size_t n, t_str *args, t_rb *ints)
{
	size_t		i;
	t_rb		xs;
	int			x;

	if (n == 1)
		xs = mstr_split_with(ft_isspace, *args);
	else
		xs = rb_from_with((t_rb_cpy)dup_str, n, sizeof(t_str), args);
	i = 0;
	while (i < xs.used)
	{
		if (get_int(((t_str *)xs.b_start)[i], &x)
				&& rb_elem_index(*ints, int_equ, &x) == -1)
			rb_grow_push_back(ints, &x);
		else
			break ;
		i += 1;
	}
	rb_iter(xs, (t_rb_iter)ft_strdel);
	free(xs.b_start);
	return (xs.used == ints->used);
}
