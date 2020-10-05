/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:36:06 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/25 15:32:58 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_xnull_crutch(t_utils *lst, int nbr)
{
	if (nbr == 0 && lst->precision && !lst->p_count)
	{
		if (!(lst->tail = ft_strdup("")))
			return (-1);
	}
	else
	{
		if (!(lst->tail = ft_uitoa_base(nbr, 16)))
			return (-1);
	}
	return (1);
}

int		ft_put_x(va_list ap, t_utils *lst, int upper)
{
	int				len;
	int				i;

	i = -1;
	if (!(ft_xnull_crutch(lst, va_arg(ap, int))))
		return (-1);
	while (lst->tail[++i] && upper)
		lst->tail[i] = ft_toupper(lst->tail[i]);
	len = ft_strlen(lst->tail);
	if (lst->precision && (lst->p_count > len))
	{
		if (!(lst->head = ft_null_maker(lst->p_count - len, 1)))
			return (-1);
		if ((len = ft_head_tail_maker(lst, 1)) == -1)
			return (-1);
	}
	if (lst->width > len)
	{
		if (ft_width_filler(lst, 1, len) == -1)
			return (-1);
	}
	ft_put_end(lst);
	return (1);
}
