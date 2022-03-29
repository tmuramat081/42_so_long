/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:58:30 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/19 11:25:10 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2042
# endif

# define FD_MAX 256

# define RETURN 1
# define CONTINUE 0
# define ERROR -1
# define END -2

typedef struct s_minfo {
	char	*mem;
	char	*ptr_nl;
	int		sts;
}	t_minfo;

char	*get_next_line(int fd);
void	read_buffer(int fd, char *buff, t_minfo *input);
char	*output_one_line(t_minfo *input);
char	*free_memory(t_minfo *input);

#endif