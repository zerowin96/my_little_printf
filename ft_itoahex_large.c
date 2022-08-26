/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahex_large.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:46:39 by yeham             #+#    #+#             */
/*   Updated: 2022/08/14 12:49:04 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sizen_l(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	else
	{
		while (n)
		{
			n = n / 16;
			i++;
		}
	}
	return (i);
}

char	*ft_itoahex_large(unsigned long long n)
{
	int					size_n;
	char				*ia;
	char				*hex;
	unsigned long long	fn;

	size_n = sizen_l(n);
	ia = (char *)ft_calloc((size_n + 1), sizeof(char));
	if (ia == NULL)
		return (0);
	hex = "0123456789ABCDEF";
	fn = n;
	while (fn)
	{
		ia[size_n - 1] = *(hex + (fn % 16));
		fn = fn / 16;
		size_n--;
	}
	if (n == 0)
		ia[0] = '0';
	return (ia);
}
