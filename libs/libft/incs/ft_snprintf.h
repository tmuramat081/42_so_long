/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:03:22 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 13:03:22 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SNPRINTF_H
# define FT_SNPRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>

/**********ft_snprintf.c**********/
int		ft_snprintf(char *buff, size_t left, const char *s, ...);
int		ft_dosnprintf(char *buff, size_t left, const char *fmt, va_list *ap);
int		switch_conv_func(char *buff, size_t *left, const char fmt, va_list *ap);
/**********sconverter.c**********/
int		copy_string_to_buff(char *buff, size_t *left, void *str);
int		convert_decimal_to_buff(char *buff, size_t *left, va_list *ap,
			bool is_signed);
int		convert_address_to_buff(char *buff, size_t *left, va_list *ap);
int		convert_hexadecimal_to_buff(char *buff, size_t *left, va_list *ap,
			bool is_large);
/**********sutils**********/
int		charcpy_buff(char *buff, size_t *left, int c);
int		strcpy_buff(char *buff, size_t *left, char *str);
char	*ft_uitoa_base(unsigned long long value, char *buff, int base);

#endif
