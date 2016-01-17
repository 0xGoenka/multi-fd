/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:12:10 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/17 21:08:16 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		n(char *s)
{
	int i;

	i= 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int 	split(char **s, char **line)
{
	char *tmp;
	char *ret;

	*line = NULL;
	if (!(ret = (char *)malloc(sizeof(char) * n(*s) + 1)))
		return (0);
	ft_bzero(ret, n(*s) +1);
	ft_strncpy(ret , *s, n(*s));
	*line = ret;
	printf("before static == %s\n", *s);
	if (s[n(*s)] == '\0')
		return (0);
	tmp = ft_strdup((*s + n(*s) + 1));
	ft_strdel(s);
	ft_strdel(&ret);
	*s = tmp;
	return (1);
}
t_lst	*multifd(t_lst *liste, int fd)
{
	t_lst *ptr;
	if (!find(liste->next,fd))
	{
		insert(liste,NULL, fd);
	}
	ptr = find(liste, fd);
	return (ptr);
}
int		get_next_line(const int fd, char **line)
{
	static	t_lst  *gnl = NULL;
	gnl =(t_lst *)malloc(sizeof(t_lst));
	gnl->next = NULL;
	gnl->index = -1;
	char	buff[BUFF_SIZE + 1];
	int ret;
	t_lst *ptr;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	ptr = multifd(gnl,fd);
	while (((ret = read(fd , buff, BUFF_SIZE)) > 0 ) && !ft_strchr(buff, '\n') &&
			!ft_strchr(buff, '\0'))
		buff[ret] = '\0', ptr->data->s = ft_strjoin(ptr->data->s, buff);
	if (ret < 0)
		return (-1);
	printf("static == %s\n", ptr->data->s);
	if (ft_strchr(buff, '\n'))
		buff[ret] = '\0', ptr->data->s = ft_strjoin(ptr->data->s, buff);
	printf("static == %s\n", ptr->data->s);
	if (!ret && !ft_strlen(ptr->data->s))
		return (0);
	if (!(split(&ptr->data->s, line)))
		*line =NULL;
	return (1);
}
