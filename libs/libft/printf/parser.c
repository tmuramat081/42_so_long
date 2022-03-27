/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:41:35 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/22 22:41:35 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	parse_specifier(const char *fmt, t_finfo *input, size_t *i)
{
	if (fmt[*i] == 'c')
		input->specifier = SP_C;
	else if (fmt[*i] == 's')
		input->specifier = SP_S;
	else if (fmt[*i] == 'd' || fmt[*i] == 'i')
		input->specifier = SP_DI;
	else if (fmt[*i] == 'u')
		input->specifier = SP_U;
	else if (fmt[*i] == 'p')
		input->specifier = SP_P;
	else if (fmt[*i] == 'x')
		input->specifier = SP_XS;
	else if (fmt[*i] == 'X')
		input->specifier = SP_XL;
	else if (fmt[*i] == '%')
		input->specifier = PER_CT;
	else
		input->specifier = SP_NONE;
}

/* Notion: if the precision is set, the zero flag will be disabled. */
void	parse_precision(const char *fmt, t_finfo *input, va_list *ap, size_t *i)
{
	int	input_num;

	if (fmt[*i] != '.')
		return ;
	*i += 1;
	if (fmt[*i] == '*')
	{
		input_num = va_arg(*ap, int);
		*i += 1;
	}
	else
	{
		input_num = ft_atoi((char *)&fmt[*i]);
		while (ft_isdigit(fmt[*i]) == true)
			(*i)++;
	}
	if (input_num < 0)
		input_num = EMPTY;
	else
		input->zero = false;
	input->precision = input_num;
}

void	parse_width(const char *fmt, t_finfo *input, va_list *ap, size_t *i)
{
	int	input_num;

	if (fmt[*i] == '*')
	{
		input_num = va_arg(*ap, int);
		(*i)++;
	}
	else if ('1' <= fmt[*i] && fmt[*i] <= '9')
	{
		input_num = ft_atoi((char *)&fmt[*i]);
		while (ft_isdigit(fmt[*i]) == true)
			(*i)++;
	}
	else
		return ;
	if (input_num < 0)
	{
		input->hyphen = true;
		input_num = -input_num;
	}
	input->width = input_num;
}

void	parse_flags(const char *fmt, t_finfo *input, size_t *i)
{
	while (fmt[*i] == '#' || fmt[*i] == '0'
		|| fmt[*i] == '-' || fmt[*i] == '+' || fmt[*i] == ' ')
	{
		if (fmt[*i] == '#')
			input->sharp = true;
		else if (fmt[*i] == '0')
			input->zero = true;
		else if (fmt[*i] == '-')
			input->hyphen = true;
		else if (fmt[*i] == '+')
			input->plus = true;
		else if (fmt[*i] == ' ')
			input->space = true;
		(*i)++;
	}
}
