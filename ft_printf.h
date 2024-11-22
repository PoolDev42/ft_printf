/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:20:47 by lcalero           #+#    #+#             */
/*   Updated: 2024/11/22 12:41:44 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

char	*ft_itoa_base(int n, const char *base);

char	*ft_ltoa_base(int n, const char *base);

char	*ft_uitoa_base(unsigned long n, const char *base);

int		ft_printf(const char *format, ...);

int		ft_handle_pointer_specifier(va_list args);

int		ft_handle_str_specifier(va_list args);

#endif