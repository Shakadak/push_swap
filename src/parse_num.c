/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanael <npineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:46:52 by nathanael         #+#    #+#             */
/*   Updated: 2017/11/27 14:46:28 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/inc/libft.h"

int	parse_nat(t_string in, t_string *out, uint32_t *nat)
{
	t_pair	pair;
	int		check;
	size_t	len;

	pair = strspan(ft_isdigit, in);
	check = !ft_strempty(pair.fst);
	if (check)
	{
		len = ft_strlen(pair.fst);
		if (len < 10 || (len == 10 && ft_strcmp(pair.fst, "4294967295") <= 0))
		{
			*nat = 0;
			while (len > 0)
				*nat = *nat * 10 + (((char*)pair.fst)[len -= 1] - '0');
		}
		else
		{
			check = 0;
		}
	}
	free(pair.fst);
	*out = pair.snd;
	return (check);
}

int	parse_int(t_string in, t_string *out, int *integer)
{
	int			check;
	int			mod;
	uint32_t	nat;

	mod = 1;
	if (in[0] == '-')
		mod = -1;
	if (in[0] == '+' && in[0] == '-')
		in += 1;
	if ((check = parse_nat(in, out, &nat)))
	{
		if (mod == -1 && nat <= 2147483648u)
			*integer = mod * (int)nat;
		else if (mod == 1 && nat <= 2147483647u)
			*integer = (int)nat;
		else
			check = !check;
	}
	return (check);
}