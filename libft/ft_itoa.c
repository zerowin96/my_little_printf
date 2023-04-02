/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:13:35 by yeham             #+#    #+#             */
/*   Updated: 2022/08/14 12:49:17 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	sizen(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		i = 1;
		while (n)
		{
			n = n / 10;
			i++;
		}
	}
	else if (n > 0)
	{
		while (n)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(long long int n)
{
	int						size_n;
	unsigned long long int	fn;
	char					*ia;

	size_n = sizen(n);
	ia = (char *)ft_calloc(size_n + 1, sizeof(char));
	if (ia == NULL)
		return (0);
	if (n < 0)
	{
		ia[0] = '-';
		fn = n * (-1);
	}
	else
		fn = n;
	while (fn)
	{
		ia[size_n - 1] = (fn % 10) + '0';
		fn = fn / 10;
		size_n--;
	}
	if (n == 0)
		ia[0] = '0';
	return (ia);
}
