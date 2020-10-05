/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:33:30 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/25 01:27:24 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_c_with_width(t_utils *lst)
{
	char	*tmp;
	int		len;

	if (!(lst->head = ft_space_maker(lst->width - 1)))
		return (-1);
	len = ft_strlen(lst->head);
	if (!lst->flag_l)
	{
		if (!(tmp = (char *)ft_memjoin(lst->head, lst->tail, len, 1)))
			return (-1);
	}
	else
	{
		if (!(tmp = (char *)ft_memjoin(lst->tail, lst->head, 1, len)))
			return (-1);
	}
	free(lst->tail);
	free(lst->head);
	lst->tail = tmp;
	return (len);
}

char	*ft_char_to_str(unsigned char c)
{
	unsigned char *str;

	if ((str = (unsigned char *)malloc(2)))
	{
		str[0] = c;
		str[1] = '\0';
	}
	return ((char *)str);
}

int		ft_put_c(va_list ap, t_utils *lst)
{
	unsigned char	c;
	int				len;

	len = 0;
	c = va_arg(ap, int);
	if (!(lst->tail = ft_char_to_str(c)))
		return (-1);
	if (lst->width > 1)
	{
		if ((len = ft_c_with_width(lst)) == -1)
			return (-1);
	}
	lst->buff = lst->tail;
	lst->buff_len = len + 1;
	return (1);
}
