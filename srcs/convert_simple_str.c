/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_simple_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:07:14 by jaham             #+#    #+#             */
/*   Updated: 2022/03/21 11:47:44 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_simple_str.h"
#include "libft.h"
#include <stdlib.h>

t_status	convert_simple_str(t_string *converted, const char **format)
{
	size_t	len;

	len = 0;
	converted->len = 0;
	while ((*format)[len] && (*format)[len] != '%')
		len++;
	converted->str = malloc(sizeof(char) * (len + 1));
	if (!converted->str)
		return (ERROR);
	while (converted->len < len)
		converted->str[converted->len++] = *((*format)++);
	converted->str[converted->len] = '\0';
	return (SUCCESS);
}
