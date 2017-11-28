/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:47:50 by npineau           #+#    #+#             */
/*   Updated: 2017/11/28 11:38:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int	args_to_stack(size_t n, char **args, t_rb *a);
int	get_program(t_rb *instructions);
int	parse_int(t_string in, t_string *out, int *integer);

#endif
