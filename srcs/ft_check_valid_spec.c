/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_spec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:00 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/24 17:28:16 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

static int	is_valid_spec(char c)
{
	return (ft_strchr(VALID_SPECIFIERS, c) != NULL);
}

int	ft_check_valid_spec(const char *format)
{
	size_t	i;

	if (!format)
		return (0);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!is_valid_spec(format[i]) || !format[i])
			{
				ft_putstr_fd("Error : invalid specifier\n", 1);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
