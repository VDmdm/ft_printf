/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 00:33:02 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/25 11:58:27 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buff_end(t_utils *lst)
{
	lst->str = lst->buff;
	lst->buff = NULL;
	lst->head = NULL;
	lst->tail = NULL;
	lst->str_len = lst->str_len - (lst->end - lst->start) + lst->buff_len;
}
