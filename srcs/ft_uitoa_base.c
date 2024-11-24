/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:04:02 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/24 17:28:25 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	count_digits_base(unsigned long n, const char *base)
{
	int				cpt;
	unsigned long	num;

	cpt = 0;
	num = n;
	while (num > 0)
	{
		num /= ft_strlen(base);
		cpt++;
	}
	if (n == 0)
		cpt = 1;
	return (cpt);
}

char	*ft_uitoa_base(unsigned long n, const char *base)
{
	char			*res;
	int				i;
	unsigned long	num;

	res = malloc(sizeof(char) * (count_digits_base(n, base) + 1));
	if (res == NULL)
		return (NULL);
	num = n;
	i = count_digits_base(n, base);
	res[i--] = '\0';
	while (num > 0)
	{
		res[i] = base[num % ft_strlen(base)];
		num /= ft_strlen(base);
		i--;
	}
	if (n == 0)
		res[i] = base[0];
	return (res);
}

/*#include <stdio.h>
/int main(void)
{
	printf("%s", ft_uitoa_base(1844674407370955161, "0123456789abcdef"));
	return (0);
}*/