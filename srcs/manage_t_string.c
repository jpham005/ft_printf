/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_t_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:51:20 by jaham             #+#    #+#             */
/*   Updated: 2022/03/21 11:06:35 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_string.h"
#include <stdlib.h>

t_status	init_t_string(t_string *string, const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	string->str = malloc(sizeof(char) * (len + 1));
	if (!string->str)
		return (ERROR);
	ft_memcpy(string->str, str, len + 1);
	string->len = len;
	return (SUCCESS);
}

t_status	append_string(t_string *s1, t_string *s2)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (s1->len + s2->len + 1));
	if (!new_str)
		return (ERROR);
	ft_memcpy(new_str, s1->str, s1->len);
	ft_memcpy(new_str + s1->len, s2->str, s2->len + 1);
	free(s1->str);
	s1->str = new_str;
	s1->len += s2->len;
	return (SUCCESS);
}
