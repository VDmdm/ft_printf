/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:19:17 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/25 16:54:08 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_utils
{
	char				*str;
	char				*buff;
	char				*head;
	char				*tail;
	int					flag_0;
	int					width;
	int					flag_sign;
	int					flag_l;
	int					precision;
	int					p_count;
	int					start;
	int					end;
	int					buff_len;
	long int			str_len;
	long int			len_all;

}				t_utils;

int				ft_printf(const char *str, ...);
int				ft_check_fow(va_list ap, t_utils *lst, int i);
int				ft_check_spec_n_run(va_list ap, t_utils *lst, int i);
int				ft_bufcat(t_utils *lst);
int				ft_putstr_printf(t_utils *lst);
int				ft_skip_nbr(t_utils *lst, int i, int st);
int				ft_get_stars(va_list ap, t_utils *lst, int i);
int				ft_get_nbr(va_list ap, t_utils *lst, int i, int flag);
int				ft_nbr_filler(t_utils *lst, int i, int flag, int st);
void			ft_zeroing_lst(t_utils *lst);
int				ft_put_d(va_list ap, t_utils *lst);
int				ft_null_crutch(t_utils *lst, int nbr);
int				ft_width_filler(t_utils *lst, int nbr, int len);
int				ft_head_tail_maker(t_utils *lst, int nbr);
int				ft_tail_head_maker(t_utils *lst);
char			*ft_null_maker(int nbr, int orig);
char			*ft_space_maker(int nbr);
int				ft_put_c(va_list ap, t_utils *lst);
char			*ft_char_to_str(unsigned char c);
int				ft_c_with_width(t_utils *lst);
int				ft_put_s(va_list ap, t_utils *lst);
char			*ft_s_prec(t_utils *lst, char *buff, int flag);
int				ft_put_u(va_list ap, t_utils *lst);
char			*ft_utoa(unsigned int n);
int				ft_put_p(va_list ap, t_utils *lst);
char			*ft_lh_str(char *str, long long int nbr, size_t count,
							size_t size);
int				ft_put_x(va_list ap, t_utils *lst, int upper);
int				ft_xnull_crutch(t_utils *lst, int nbr);
int				ft_put_perc(t_utils *lst);
int				ft_p_nbr(t_utils *lst, long long int nbr);
int				ft_p_wp_checker(t_utils *lst);
int				ft_put_error(t_utils *lst);
char			*ft_utoa(unsigned int n);
void			ft_put_end(t_utils *lst);
void			ft_buff_end(t_utils *lst);

#endif
