/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:58:40 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/25 16:13:57 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_check_spec_n_run(va_list ap, t_utils *lst, int i)
{
	if (lst->str[i] == '%')
		return (ft_put_perc(lst));
	if (lst->str[i] == 'd' || lst->str[i] == 'i')
		return (ft_put_d(ap, lst));
	if (lst->str[i] == 's')
		return (ft_put_s(ap, lst));
	if (lst->str[i] == 'c')
		return (ft_put_c(ap, lst));
	if (lst->str[i] == 'p')
		return (ft_put_p(ap, lst));
	if (lst->str[i] == 'u')
		return (ft_put_u(ap, lst));
	if (lst->str[i] == 'x')
		return (ft_put_x(ap, lst, 0));
	if (lst->str[i] == 'X')
		return (ft_put_x(ap, lst, 1));
	if (lst->str[i] == '\0')
		return (-1);
	return (0);
}

int		ft_check_fow(va_list ap, t_utils *lst, int i)
{
	while (lst->str[i] == '-' || lst->str[i] == '0')
	{
		if (lst->str[i] == '-')
			lst->flag_l = 1;
		else
			lst->flag_0 = 1;
		i++;
	}
	if (!(i = ft_get_nbr(ap, lst, i, 0)))
		return (-1);
	if (lst->str[i] == '.')
	{
		lst->precision = 1;
		i++;
		if (!(i = ft_get_nbr(ap, lst, i, 1)))
			return (-1);
	}
	if (lst->flag_l || lst->precision)
		lst->flag_0 = 0;
	return (i);
}

int		ft_str_run(va_list ap, t_utils *lst)
{
	int		i;
	int		chk;

	i = 0;
	while (lst->str[i] != 0)
	{
		if (lst->str[i] == '%')
		{
			lst->start = i;
			i = ft_check_fow(ap, lst, ++i);
			chk = ft_check_spec_n_run(ap, lst, i);
			if (chk == -1)
				return (-1);
			else if (chk == 1)
			{
				lst->end = i + 1;
				ft_bufcat(lst);
				i = lst->start + lst->buff_len - 1;
			}
			ft_zeroing_lst(lst);
		}
		i++;
	}
	lst->len_all = i;
	return (1);
}

int		ft_printf(const char *str, ...)
{
	t_utils	*lst;
	va_list	ap;

	if (!str)
		return (-1);
	if (!(lst = (t_utils *)malloc(sizeof(t_utils))))
		return (-1);
	if (!(lst->str = ft_strdup((char *)str)))
		return (-1);
	lst->len_all = 0;
	lst->str_len = ft_strlen(lst->str) + 1;
	va_start(ap, str);
	ft_zeroing_lst(lst);
	if (ft_str_run(ap, lst) == -1)
		return (ft_put_error(lst));
	return (ft_putstr_printf(lst));
}
