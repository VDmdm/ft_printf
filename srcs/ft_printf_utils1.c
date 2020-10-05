/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:58:40 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/25 16:53:55 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_bufcat(t_utils *lst)
{
	size_t	len;
	char	*tmp;

	if (!(lst->head = (char *)ft_memsub(lst->str, 0, lst->start)))
		return (-1);
	if (!(lst->tail = (char *)ft_memsub(lst->str, lst->end,
						(size_t)lst->str_len)))
		return (-1);
	len = lst->str_len - lst->end;
	if (!(tmp = (char *)ft_memjoin(lst->head, lst->buff, lst->start,
						lst->buff_len)))
		return (-1);
	free(lst->str);
	lst->str = tmp;
	free(lst->buff);
	free(lst->head);
	if (!(lst->buff = (char *)ft_memjoin(lst->str, lst->tail, lst->start +
						lst->buff_len, len)))
		return (-1);
	free(lst->str);
	free(lst->tail);
	ft_buff_end(lst);
	return (1);
}

int		ft_get_stars(va_list ap, t_utils *lst, int i)
{
	int		start_tmp;
	int		nbr;

	start_tmp = lst->start;
	lst->start = i;
	lst->end = i + 1;
	nbr = va_arg(ap, int);
	if (nbr)
	{
		if (!(lst->buff = ft_itoa(nbr)))
			return (-1);
	}
	else
	{
		if (!(lst->buff = ft_strdup("")))
			return (-1);
	}
	lst->buff_len = ft_strlen(lst->buff);
	if (ft_bufcat(lst) == -1)
		return (-1);
	lst->start = start_tmp;
	return (i);
}

int		ft_nbr_filler(t_utils *lst, int i, int flag, int st)
{
	if (flag == 0)
		lst->width = ft_atoi(&(lst->str[i]));
	else
		lst->p_count = ft_atoi(&(lst->str[i]));
	return (ft_skip_nbr(lst, i, st));
}

int		ft_get_nbr(va_list ap, t_utils *lst, int i, int flag)
{
	int		star;
	int		st;

	star = 0;
	st = 0;
	if (lst->str[i] == '*' && (lst->str[i + 1] >= '0' &&
		lst->str[i + 1] <= '9'))
		star = 1;
	if (lst->str[i] == '*')
	{
		st = 1;
		if ((i = ft_get_stars(ap, lst, i)) == -1)
			return (-1);
	}
	if (lst->str[i] == '-' && !flag && !star)
	{
		lst->flag_l = 1;
		lst->flag_0 = 0;
		i++;
	}
	if (lst->str[i] != '*' && !star)
		return (ft_nbr_filler(lst, i, flag, st));
	return (i);
}

int		ft_skip_nbr(t_utils *lst, int i, int st)
{
	if (lst->str[i] == '-' && lst->str[i + 1] <= '9' &&
		lst->str[i + 1] >= '0' && st)
		i++;
	while (lst->str[i] >= '0' && lst->str[i] <= '9' && lst->str[i])
		i++;
	return (i);
}
