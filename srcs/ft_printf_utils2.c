/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 21:39:09 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/25 12:23:48 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_zeroing_lst(t_utils *lst)
{
	lst->flag_0 = 0;
	lst->width = 0;
	lst->flag_sign = 0;
	lst->flag_l = 0;
	lst->precision = 0;
	lst->p_count = 0;
	lst->start = 0;
	lst->end = 0;
	lst->buff_len = 0;
}

int		ft_putstr_printf(t_utils *lst)
{
	int i;

	i = 0;
	while (lst->len_all--)
		i += write(1, &lst->str[i], 1);
	free(lst->str);
	free(lst);
	return (i);
}

int		ft_put_error(t_utils *lst)
{
	int i;

	i = 0;
	while (i < lst->start)
	{
		write(1, &lst->str[i], 1);
		i++;
	}
	free(lst->str);
	free(lst);
	return (i);
}

void	ft_put_end(t_utils *lst)
{
	lst->buff = lst->tail;
	lst->buff_len = ft_strlen(lst->buff);
	lst->tail = NULL;
}
