/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:06:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/17 18:41:48 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 29

# include "libft/libft.h"
# include "../list/list.h"
# include <stdio.h>

typedef struct	s_gnl
{
	char *s;
	int fd;
	struct s_gnl *next;
}				t_gnl;

int get_next_line(int const fd, char **line);


#endif
