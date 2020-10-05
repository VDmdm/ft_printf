/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_perc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:49:36 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/23 01:44:29 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_put_perc(t_utils *lst)
{
	if (!(lst->tail = ft_strdup("%")))
		return (-1);
	if (lst->width > 1)
	{
		if (!(lst->head = ft_space_maker(lst->width - 1)))
			return (-1);
		if (!lst->flag_l)
		{
			if (ft_head_tail_maker(lst, 1) == -1)
				return (-1);
		}
		else
		{
			if (ft_tail_head_maker(lst) == -1)
				return (-1);
		}
		free(lst->head);
	}
	ft_put_end(lst);
	return (1);
}
