/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:30:41 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/22 12:44:48 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

#include <stdio.h>

static void	convert_print_num(int *len, const char *base, va_list args, char sp)
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

	if (s[i] != '%')
		return (0);
	str = NULL;
	if (s[i + 1] == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1), 1);
	else if (s[i + 1] == '%')
		return (ft_putchar_fd('%', 1), 1);
	else if (s[i + 1] == 's')
		return (ft_handle_str_specifier(args));
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		return (convert_print_num(&len, "0123456789", args, 'd'), len);
	if (s[i + 1] == 'p')
		return (ft_handle_pointer_specifier(args));
	else if (s[i + 1] == 'u')
		return (convert_print_num(&len, "0123456789", args, 'u'), len);
	else if (s[i + 1] == 'x')
		return (convert_print_num(&len, "0123456789abcdef", args, 'x'), len);
	else if (s[i + 1] == 'X')
		return (convert_print_num(&len, "0123456789ABCDEF", args, 'X'), len);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	int			res;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			res += check_specifier(format, i, args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			res++;
			i++;
		}
	}
	va_end(args);
	return (res);
}

/*int	main(void)
{
	//int	a = 0;
	printf("%d", ft_printf("%s\n", "salut les amis"));
	//ft_printf(0);
	return (0);
}*/