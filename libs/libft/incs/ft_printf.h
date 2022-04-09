/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:32:40 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/24 02:00:41 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>

# define EMPTY -1

# define ST_POSITIVE 0
# define ST_NEGATIVE 1
# define ST_ERROR 2

/* Support for cspdiuxX. */
typedef enum e_spec {
	SP_C,
	SP_S,
	SP_DI,
	SP_U,
	SP_P,
	SP_XS,
	SP_XL,
	PER_CT,
	SP_NONE,
	E_END
}	t_spec;

typedef struct s_finfo {
	bool	hyphen;
	bool	plus;
	bool	zero;
	bool	sharp;
	bool	space;
	int		width;
	int		precision;
	t_spec	specifier;
}	t_finfo;

/* For example ' -42',  1. body '42',  2. prefix '-', 3. padding ' '  */
typedef struct s_print {
	char	*body;
	char	*prefix;
	char	*padding;
	int		status;
}	t_print;

typedef int(*t_parrfunc[E_END])(va_list *, t_finfo);

/**********ft_printf.c**********/
int		ft_printf(const char *s, ...);
/**********doprintf.c**********/
int		ft_doprintf(const char *fmt, va_list *ap);
int		print_arguments(const char *fmt, va_list *ap, size_t *i);
int		switch_conv_function(va_list *ap, t_finfo input, const char *fmt);
int		put_syntax_error(const char *fmt);
/**********parcer.c**********/
void	parse_flags(const char *fmt, t_finfo *input, size_t *i);
void	parse_width(const char *fmt, t_finfo *input, va_list *ap, size_t *i);
void	parse_precision(const char *fmt, t_finfo *input, va_list *ap,
			size_t *i);
void	parse_specifier(const char *fmt, t_finfo *input, size_t *i);
/**********converter.c**********/
int		convert_into_char_and_print(va_list *ap, t_finfo input);
int		convert_into_string(va_list *ap, t_finfo input);
int		convert_into_decimal(va_list *ap, t_finfo input);
int		convert_into_address(va_list *ap, t_finfo input);
int		convert_into_hexadecimal(va_list *ap, t_finfo input);
/**********composer.c**********/
void	set_body(unsigned long long value, int base, t_print *output,
			t_finfo input);
void	set_prefix(t_print *output, t_finfo input);
void	set_padding(t_print *output, t_finfo input);
void	apply_precision(unsigned long long value, t_print *output,
			t_finfo input);
char	*zerojoin_free(char *src, size_t len);
/**********printer.c**********/
void	free_output(t_print *output);
int		setup_field(t_print *output, t_finfo input);
int		print_field(char *str1, char *str2, char *str3);
/**********utils**********/
char	*ft_itoa_base(unsigned long long value, char *buff, int base);
int		ft_putstr_cnt(char *str);
int		ft_putchar_cnt(int c);
void	str_toupper(char *str);
int		ft_strlen_s(const char *c);

#endif
