/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:43:21 by yeham             #+#    #+#             */
/*   Updated: 2022/08/14 12:57:31 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char *bs, va_list ap)
{
	if (*bs == 'c')
		return (go_c(ap));
	else if (*bs == 's')
		return (go_s(ap));
	else if (*bs == 'p')
		return (go_p(ap));
	else if (*bs == 'd' || *bs == 'i')
		return (go_d(ap));
	else if (*bs == 'u')
		return (go_u(ap));
	else if (*bs == 'x')
		return (go_x(ap));
	else if (*bs == 'X')
		return (go_lx(ap));
	else if (*bs == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (-1);
}

int	check(const char *bs, va_list ap)
{
	int	i;
	int	type_len;

	if (bs == 0)
		return (-1);
	i = 0;
	while (*bs)
	{
		if (*bs == '%')
		{
			bs++;
			type_len = check_type(bs, ap);
			if (type_len == -1)
				return (-1);
			i += type_len;
		}
		else
		{
			if (write(1, bs, 1) == -1)
				return (-1);
			i++;
		}
		bs++;
	}
	return (i);
}

int	ft_printf(const char *bs, ...)
{
	va_list	ap;
	int		answer;

	answer = 0;
	va_start(ap, bs);
	answer = check(bs, ap);
	va_end(ap);
	return (answer);
}
