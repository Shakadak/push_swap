/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:47:50 by npineau           #+#    #+#             */
/*   Updated: 2017/11/30 08:09:57 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/libft.h"

int	args_to_stack(size_t n, t_str *args, t_rb *a);
int	get_program(t_rb *instructions);
int	parse_int(t_str in, t_str *out, int *integer);

#endif
