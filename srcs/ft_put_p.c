/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:21:32 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/25 01:33:09 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_p_wp_checker(t_utils *lst)
{
	int				len;

	len = ft_strlen(lst->tail) + (!lst->precision && lst->flag_0 ? 2 : 0);
	if (lst->width > len)
	{
		if (ft_width_filler(lst, 1, len) == -1)
			return (-1);
	}
	if (!lst->precision && lst->flag_0)
	{
		if (!(lst->head = ft_strdup("0x")) ||
			(len = ft_head_tail_maker(lst, 1)) == -1)
			return (-1);
	}
	return (1);
}

int		ft_p_nbr(t_utils *lst, long long int nbr)
{
	int				len;

	if (!(lst->tail = ft_ultoa_base(nbr, 16)))
		return (-1);
	len = ft_strlen(lst->tail);
	if (lst->precision && (lst->p_count > len))
	{
		if (!(lst->head = ft_null_maker(lst->p_count - len, 1)))
			return (-1);
		if ((len = ft_head_tail_maker(lst, 1)) == -1)
			return (-1);
	}
	if ((lst->precision || lst->flag_l || !lst->flag_0))
	{
		if (!(lst->head = ft_strdup("0x")) ||
			(len = ft_head_tail_maker(lst, 1)) == -1)
			return (-1);
	}
	return (1);
}

int		ft_put_p(va_list ap, t_utils *lst)
{
	long long int	nbr;

	nbr = va_arg(ap, long long int);
	if (!nbr && lst->precision && !lst->p_count)
	{
		if (!(lst->tail = ft_strdup("0x")))
			return (-1);
	}
	else
	{
		if (ft_p_nbr(lst, nbr) == -1)
			return (-1);
	}
	ft_p_wp_checker(lst);
	ft_put_end(lst);
	return (1);
}
