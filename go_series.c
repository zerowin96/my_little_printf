/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_series.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:07:25 by yeham             #+#    #+#             */
/*   Updated: 2022/08/14 12:58:53 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	go_c(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	go_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (write(1, s, ft_strlen(s)) == -1 || ft_strlen(s) > 2147483646)
		return (-1);
	return (ft_strlen(s));
}

int	go_p(va_list ap)
{
	unsigned long long	p;
	char				*pitoa;
	int					len;

	p = (unsigned long long)va_arg(ap, void *);
	pitoa = ft_itoahex(p);
	len = ft_strlen(pitoa);
	write(1, "0x", 2);
	if (write(1, pitoa, len) == -1)
	{
		free(pitoa);
		return (-1);
	}
	free(pitoa);
	return (len + 2);
}

int	go_d(va_list ap)
{
	int		d;
	char	*ditoa;
	int		len;

	d = va_arg(ap, int);
	ditoa = ft_itoa(d);
	len = ft_strlen(ditoa);
	if (write(1, ditoa, len) == -1)
	{
		free(ditoa);
		return (-1);
	}
	free(ditoa);
	return (len);
}

int	go_u(va_list ap)
{
	unsigned int	u;
	char			*uitoa;
	int				len;

	u = va_arg(ap, unsigned int);
	uitoa = ft_itoa(u);
	len = ft_strlen(uitoa);
	if (write(1, uitoa, len) == -1)
	{
		free(uitoa);
		return (-1);
	}
	free(uitoa);
	return (len);
}
