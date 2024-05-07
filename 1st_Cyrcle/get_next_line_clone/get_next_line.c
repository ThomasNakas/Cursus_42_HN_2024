/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:13:58 by tnakas            #+#    #+#             */
/*   Updated: 2024/04/23 18:51:32 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	static char	*rem;
	char		*tstr;

	if (fd > 0 && (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0))
		return (free(rem), rem = NULL, NULL);
	if (fd < 0)
		return (free(rem), rem = NULL, NULL);
	rem = get_res(fd, rem);
	if (!rem)
		return (NULL);
	res = ft_substr(rem, 0, ft_linelen(rem));
	if (!res)
		return (free(res), free(rem), rem = NULL, NULL);
	if (res[0] == '\0')
		return (free(res), free(rem), rem = NULL, NULL);
	tstr = ft_substr(rem, ft_linelen(rem),
			ft_strlen(rem) - ft_linelen(rem));
	free(rem);
	rem = ft_substr(tstr, 0, ft_strlen(tstr));
	free(tstr);
	return (res);
}

char	*get_res(int fd, char *rem)
{
	char		temp[BUFFER_SIZE + 1];
	int			read_c;
	int			len;

	read_c = 1;
	if (rem == NULL)
		rem = ft_substr("", 0, 1);
	len = ft_strlen(rem);
	while (read_c > 0)
	{
		read_c = read(fd, temp, BUFFER_SIZE);
		if (read_c < 0)
			return (free(rem), rem = NULL, NULL);
		if (read_c == 0)
			break ;
		len += read_c;
		temp[read_c] = '\0';
		rem = ft_strjoin(rem, temp, len);
		if (ft_str_bs(temp, '\n') >= 0)
			break ;
	}
	return (rem);
}
