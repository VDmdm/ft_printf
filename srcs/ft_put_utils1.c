/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:31:56 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/23 01:29:13 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_head_tail_maker(t_utils *lst, int nbr)
{
	char	*tmp;

	if (nbr < 0 && (lst->flag_0 || lst->precision))
	{
		if (!(tmp = ft_strjoin(lst->head, lst->tail + 1)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strjoin(lst->head, lst->tail)))
			return (-1);
	}
	free(lst->head);
	free(lst->tail);
	lst->tail = tmp;
	lst->head = NULL;
	return (ft_strlen(lst->tail));
}

int		ft_tail_head_maker(t_utils *lst)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(lst->tail, lst->head)))
		return (-1);
	free(lst->head);
	free(lst->tail);
	lst->tail = tmp;
	lst->head = NULL;
	return (ft_strlen(lst->tail));
}

char	*ft_space_maker(int nbr)
{
	char	*buff;
	int		i;

	i = 0;
	if (!(buff = (char *)malloc(nbr + 1)))
		return (0);
	while (i < nbr)
	{
		buff[i] = ' ';
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*ft_null_maker(int nbr, int orig)
{
	int		i;
	char	*buff;

	i = (orig < 0 ? 1 : 0);
	if (!(buff = (char *)malloc(nbr + ((orig < 0) ? 2 : 1))))
		return (0);
	if (orig < 0)
	{
		buff[0] = '-';
		nbr++;
	}
	while (i < nbr)
	{
		buff[i] = '0';
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

int		ft_width_filler(t_utils *lst, int nbr, int len)
{
	if (!lst->flag_l && lst->flag_0 && !lst->precision)
	{
		if (!(lst->head = ft_null_maker(lst->width - len, nbr)))
			return (-1);
	}
	else if (!lst->flag_0 || lst->flag_l || lst->precision)
	{
		if (!(lst->head = ft_space_maker(lst->width - len)))
			return (-1);
	}
	if (lst->flag_l)
	{
		if ((ft_tail_head_maker(lst)) == -1)
			return (-1);
	}
	else
	{
		if ((ft_head_tail_maker(lst, nbr)) == -1)
			return (-1);
	}
	free(lst->head);
	return (1);
}
