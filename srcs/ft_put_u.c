/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:35:56 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/23 00:35:20 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	unsigned int	buff;
	int				count;
	char			*str;

	buff = n;
	count = 1;
	while ((buff = buff / 10))
		count++;
	if (!(str = ft_calloc(1, count + 1)))
		return (0);
	while (count)
	{
		buff = (n % 10);
		n = n / 10;
		str[count - 1] = buff + 48;
		count--;
	}
	return (str);
}

int		ft_unull_crutch(t_utils *lst, unsigned int nbr)
{
	if (nbr == 0 && lst->precision && lst->p_count == 0)
	{
		if (!(lst->tail = ft_strdup("")))
			return (-1);
	}
	else
	{
		if (!(lst->tail = ft_utoa(nbr)))
			return (-1);
	}
	return (1);
}

int		ft_put_u(va_list ap, t_utils *lst)
{
	int				len;
	unsigned int	nbr;

	nbr = va_arg(ap, unsigned int);
	if (ft_unull_crutch(lst, nbr) == -1)
		return (-1);
	len = ft_strlen(lst->tail);
	if (lst->precision && (lst->p_count > len))
	{
		if (!(lst->head = ft_null_maker(lst->p_count - len, 1)))
			return (-1);
		if ((len = ft_head_tail_maker(lst, 1)) == -1)
			return (-1);
	}
	lst->precision = 0;
	if (lst->width > len)
	{
		if (ft_width_filler(lst, 1, len) == -1)
			return (-1);
	}
	ft_put_end(lst);
	return (1);
}
