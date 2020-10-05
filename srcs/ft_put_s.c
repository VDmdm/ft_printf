/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:33:35 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/26 22:37:13 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_s_prec(t_utils *lst, char *buff, int flag)
{
	char	*tmp;

	if (!(tmp = (char *)ft_calloc(1, lst->p_count + 1)))
		return (0);
	while (lst->p_count--)
		tmp[lst->p_count] = buff[lst->p_count];
	if (flag)
		free(buff);
	return (tmp);
}

char	*ft_s_check(t_utils *lst, char *buff)
{
	int		len;
	int		flag;

	flag = 0;
	if (!buff)
	{
		if (!(buff = ft_strdup("(null)")))
			return (0);
		flag = 1;
	}
	len = ft_strlen(buff);
	if (lst->precision && lst->p_count < len && lst->p_count >= 0)
		return (ft_s_prec(lst, buff, flag));
	if (flag)
	{
		free(buff);
		return (ft_strdup("(null)"));
	}
	return (ft_strdup(buff));
}

int		ft_put_s(va_list ap, t_utils *lst)
{
	int		len;
	char	*buff;

	buff = va_arg(ap, char *);
	if (!(lst->tail = ft_s_check(lst, buff)))
		return (-1);
	len = ft_strlen(lst->tail);
	if (!lst->flag_l && lst->width > len)
	{
		if (!(lst->head = ft_space_maker(lst->width - len)))
			return (-1);
		if ((ft_head_tail_maker(lst, 1)) == -1)
			return (-1);
	}
	else if (lst->flag_l && lst->width > len)
	{
		if (!(lst->head = ft_space_maker(lst->width - len)))
			return (-1);
		if ((ft_tail_head_maker(lst)) == -1)
			return (-1);
	}
	ft_put_end(lst);
	return (1);
}
