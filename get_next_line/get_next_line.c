/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaziki <noaziki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:46:52 by noaziki           #+#    #+#             */
/*   Updated: 2025/05/22 10:56:44 by noaziki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1337
#endif

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char *get_next_line(int fd)
{
    int i = 0;
    static int buff_pos = 0;
    static int buff_read = 0;
    static char buff[BUFFER_SIZE];
    char line[70000];
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if(buff_pos >= buff_read)
        {
            buff_read = read(fd,buff,BUFFER_SIZE);
            buff_pos = 0;
            if(buff_read < 0)
                return (NULL);
            if(buff_read == 0)
                break;
        }
        line[i++] = buff[buff_pos++];
        if(line[i-1] =='\n' || i >= (int)sizeof(line) - 1)
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}