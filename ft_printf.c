/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:30:41 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/21 19:35:16 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

#include <stdio.h>

static void	ft_fill_string(int *len, const char *base, va_list args, char sp)
{
	char	*s;

	s = NULL;
	if (sp == 'x' || sp == 'X')
		s = ft_ltoa_base((long)va_arg(args, unsigned int), base);
	else if (sp == 'u')
		s = ft_uitoa_base((unsigned long)va_arg(args, unsigned), base);
	else if (sp == 'd' || sp == 'i')
		s = ft_itoa_base((long)va_arg(args, int), base);
	else
		return ;
	ft_putstr_fd(s, 1);
	*len = ft_strlen(s);
	free(s);
}

static int	check_specifier(const char *s, int i, va_list args)
{
	char	*str;
	int		len;

	str = NULL;
	if (s[i] != '%')
		return (0);
	if (s[i + 1] == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1), 1);
	else if (s[i + 1] == '%')
		return (ft_putchar_fd('%', 1), 1);
	else if (s[i + 1] == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (ft_putstr_fd("(null)", 1), 6);
		return (ft_putstr_fd(str, 1), ft_strlen(str));
	}
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		return (ft_fill_string(&len, "0123456789", args, 'd'), len);
	return (0);
}

static int	check_base_specifier(const char *s, int i, va_list args)
{
	char	*str;
	int		len;
	long	arg;

	len = 0;
	str = NULL;
	if (s[i + 1] == 'p')
	{
		arg = (long)va_arg(args, void *);
		if (arg == 0)
			return (ft_putstr_fd("(nil)", 1), 5);
		ft_putstr_fd("0x", 1);
		str = ft_uitoa_base(arg, "0123456789abcdef");
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
		return (free(str), len + 2);
	}
	else if (s[i + 1] == 'u')
		return (ft_fill_string(&len, "0123456789", args, 'u'), len);
	else if (s[i + 1] == 'x')
		return (ft_fill_string(&len, "0123456789abcdef", args, 'x'), len);
	else if (s[i + 1] == 'X')
		return (ft_fill_string(&len, "0123456789ABCDEF", args, 'X'), len);
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
			res += check_specifier(s, i, args);
			res += check_base_specifier(s, i, args);
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
	printf("%p\n", &a);
	ft_printf("%p\n", &a);
	return (0);
}*/