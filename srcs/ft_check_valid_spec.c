/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_spec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:00 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/26 21:16:20 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	ft_check_valid_spec(const char *format)
{
	size_t	i;
	size_t	j;
	size_t	cpt;

	if (!format)
		return (0);
	i = 0;
	j = 0;
	cpt = 0;
	while (format[i])
	{
		while (format[i + j] == '%')
		{
			j++;
			cpt++;
		}
		if (cpt % 2 != 0)
			return (0);
		j = 0;
		cpt = 0;
		i++;
	}
	return (1);
}
