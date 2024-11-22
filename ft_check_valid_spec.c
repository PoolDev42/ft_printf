/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_spec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:00 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/22 13:56:56 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	is_valid_spec(char c)
{
	if (c == 'c' || c == 's' || c == '%'
		|| c == 'x' || c == 'X' || c == 'p'
		|| c == 'u' || c == 'd' || c == 'i')
		return (1);
	return (0);
}

int	ft_check_valid_spec(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && !is_valid_spec(format[i + 1]))
		{
			ft_putstr_fd("invalid specifier\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}
