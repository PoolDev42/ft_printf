/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:30:41 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/21 12:15:09 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

#include <stdio.h>

static int	determine_specifier(const char *s, int i, va_list args)
{
	char	*str;
	int		len;

	if (s[i] == '%')
	{
		if (s[i + 1] == 'c')
			return (ft_putchar_fd((char)va_arg(args, int), 1), 1);
		else if (s[i + 1] == '%')
			return (ft_putchar_fd('%', 1), 1);
		else if (s[i + 1] == 's')
		{
			str = va_arg(args, char *);
			ft_putstr_fd(str, 1);
			return(ft_strlen(str));
		}
		else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		{
			str = ft_itoa_base(va_arg(args, int), "0123456789");
			ft_putstr_fd(str, 1);
			len = ft_strlen(str);
			return(free(str), len);
		}
		else
			ft_putstr_fd("unknown format", 1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	size_t		i;
	int			res;

	va_start(args, s);
	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			res += determine_specifier(s, i, args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			res++;
			i++;
		}
	}
	va_end(args);
	return (res);
}

/*int	main(void)
{
	int	a = 0;
	printf("  %d\n", ft_printf("skibidi%d%d%dskibidi", a, a, a));
	//printf("%d", a);
	return (0);
}*/