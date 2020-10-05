/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:33:38 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/25 01:35:59 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_null_crutch(t_utils *lst, int nbr)
{
	if (nbr == 0 && lst->precision && lst->p_count == 0)
	{
		if (!(lst->tail = ft_strdup("")))
			return (-1);
	}
	else
	{
		if (!(lst->tail = ft_itoa(nbr)))
			return (-1);
	}
	if (nbr < 0)
		lst->p_count += 1;
	return (1);
}

int		ft_put_d(va_list ap, t_utils *lst)
{
	int		len;
	int		nbr;

	nbr = va_arg(ap, int);
	if (ft_null_crutch(lst, nbr) == -1)
		return (-1);
	len = ft_strlen(lst->tail);
	if (lst->precision && (lst->p_count > len))
	{
		if (!(lst->head = ft_null_maker(lst->p_count - len, nbr)))
			return (-1);
		if ((len = ft_head_tail_maker(lst, nbr)) == -1)
			return (-1);
	}
	lst->precision = 0;
	if (lst->width > len)
	{
		if (ft_width_filler(lst, nbr, len) == -1)
			return (-1);
	}
	ft_put_end(lst);
	return (1);
}
