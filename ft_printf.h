/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:00:13 by yeham             #+#    #+#             */
/*   Updated: 2022/08/14 12:58:05 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int					ft_printf(const char *bs, ...);
char				*ft_itoahex(unsigned long long n);
char				*ft_itoahex_large(unsigned long long n);
int					go_c(va_list ap);
int					go_s(va_list ap);
int					go_p(va_list ap);
int					go_d(va_list ap);
int					go_u(va_list ap);
int					go_x(va_list ap);
int					go_lx(va_list ap);

#endif
