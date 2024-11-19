/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:06:12 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/19 15:19:04 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	count_digits_base(int n, const char *base)
{
	long	num;
	int		cpt;

	cpt = 0;
	num = (long) n;
	if (num < 0)
	{
		cpt++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= ft_strlen(base);
		cpt++;
	}
	if (n == 0)
		cpt = 1;
	return (cpt);
}

#include <stdio.h>
char	*ft_itoa_base(int n, const char *base)
{
	char	*res;
	int		i;
	long	num;

	res = malloc(sizeof(char) * count_digits_base(n, base) + 1);
	if (res == NULL)
		return (NULL);
	i = count_digits_base(n, base);
	num = (long) n;
	if (n < 0)
		num = -num;
	res[i--] = '\0';
	while (num > 0)
	{
		res[i] = base[num % ft_strlen(base)];
		num /= ft_strlen(base);
		i--;
	}
	if (n < 0)
		res[i] = '-';
	if (n == 0)
		res[i] = base[0];
	return (res);
}

/*int main(void)
{
	printf("%s", ft_itoa_base(12, "0123456789abcdef"));
	return (0);
}*/