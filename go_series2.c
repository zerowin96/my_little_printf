/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_series2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:13:42 by yeham             #+#    #+#             */
/*   Updated: 2022/08/14 12:58:18 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	go_x(va_list ap)
{
	unsigned int	x;
	char			*xitoa;
	int				len;

	x = va_arg(ap, unsigned int);
	xitoa = ft_itoahex(x);
	len = ft_strlen(xitoa);
	if (write(1, xitoa, len) == -1)
	{
		free(xitoa);
		return (-1);
	}
	free(xitoa);
	return (len);
}

int	go_lx(va_list ap)
{
	unsigned int	lx;
	char			*lxitoa;
	int				len;

	lx = va_arg(ap, unsigned int);
	lxitoa = ft_itoahex_large(lx);
	len = ft_strlen(lxitoa);
	if (write(1, lxitoa, len) == -1)
	{
		free(lxitoa);
		return (-1);
	}
	free(lxitoa);
	return (len);
}
