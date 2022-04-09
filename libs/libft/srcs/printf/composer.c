/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:57:34 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/23 23:45:13 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*zerojoin_free(char *src, size_t len)
{
	char	*buff;
	char	*dst;

	buff = ft_calloc(len + 1, sizeof(char));
	if (!buff)
		return (NULL);
	ft_memset(buff, '0', len);
	dst = ft_strjoin(buff, src);
	free(buff);
	free(src);
	return (dst);
}

/* If the precision is longer than digits, add '0' characters. */
void	apply_precision(unsigned long long value,
			t_print *output, t_finfo input)
{
	size_t	b_len;

	if (input.precision == 0 && value == 0)
	{
		free(output->body);
		output->body = NULL;
		return ;
	}
	b_len = ft_strlen_s(output->body);
	if (b_len < (size_t)input.precision)
	{
		output->body = zerojoin_free(output->body, input.precision - b_len);
		if (!output->body)
		{
			output->status = ST_ERROR;
			return ;
		}
	}
}

/* Make the 'padding' part, which is provived by field width(space or 0). */
void	set_padding(t_print *output, t_finfo input)
{
	int		body_len;
	int		prefix_len;
	int		padding_len;

	if (input.width == EMPTY || input.width == 0)
		return ;
	body_len = ft_strlen_s(output->body);
	prefix_len = ft_strlen_s(output->prefix);
	padding_len = input.width - body_len - prefix_len;
	if (0 < padding_len)
	{
		output->padding = ft_calloc(padding_len + 1, sizeof(char));
		if (!output->padding)
		{
			output->status = ST_ERROR;
			return ;
		}
		if (input.zero == true)
			ft_memset(output->padding, '0', padding_len);
		else
			ft_memset(output->padding, ' ', padding_len);
	}
}

/* Make the 'prefix' part, which conteins +, -, 0x, etc... */
void	set_prefix(t_print *output, t_finfo input)
{
	if (input.specifier == SP_P || input.sharp == true)
	{
		if (input.specifier == SP_XL)
			output->prefix = ft_strdup("0X");
		else
			output->prefix = ft_strdup("0x");
	}
	else if (output->status == ST_NEGATIVE)
		output->prefix = ft_strdup("-");
	else if (output->status == ST_POSITIVE && input.specifier == SP_DI)
	{
		if (input.plus == true)
			output->prefix = ft_strdup("+");
		else if (input.space == true)
			output->prefix = ft_strdup(" ");
	}
}

/* Make the 'body' part, which is actual number or string. */
void	set_body(unsigned long long value, int base,
			t_print *output, t_finfo input)
{
	output->body = malloc((sizeof (char) * 16 + 1));
	if (!output->body)
	{
		output->status = ST_ERROR;
		return ;
	}
	ft_itoa_base(value, output->body, base);
	if (input.precision != EMPTY)
		apply_precision(value, output, input);
}
