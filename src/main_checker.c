/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:58:41 by npineau           #+#    #+#             */
/*   Updated: 2017/12/01 09:56:45 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"
#include "inc/push_swap.h"

static int	cleanup(t_rb stacks[2], t_rb instructions, int fd, t_str msg)
{
	free(stacks[0].b_start);
	free(stacks[1].b_start);
	rb_iter(instructions, (t_rb_iter)ft_strdel);
	free(instructions.b_start);
	ft_putendl_fd(msg, fd);
	return (fd == STDERR_FILENO);
}

static void	printnum(void *nbr) // TODO remove
{
	ft_putnbrendl(*(int*)nbr);
}

int			main(int argc, t_str *argv)
{
	t_rb	stacks[2];
	t_rb	instructions;

	rb_new(imax(argc - 1, 16), sizeof(int), &stacks[0]);
	rb_new(imax(argc - 1, 16), sizeof(int), &stacks[1]);
	rb_new(16, sizeof(t_str), &instructions);
	if (argc > 1 && !args_to_stack(argc - 1, argv + 1, &stacks[0]))
	{
		rb_iter(stacks[0], printnum); // TODO remove
		return (cleanup(stacks, instructions, STDERR_FILENO, "Error"));
	}
	rb_iter(stacks[0], printnum); // TODO remove
	if (!get_program(&instructions))
	{
		return (cleanup(stacks, instructions, STDERR_FILENO, "Error"));
	}
	//return (cleanup(stacks, instructions, STDOUT_FILENO, "KO"));
	return (0);
}
