/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:36:26 by jaham             #+#    #+#             */
/*   Updated: 2022/03/20 22:42:33 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_simple_str.h"
#include "libft.h"
#include "t_string.h"
#include <stdarg.h>

static t_status	get_buf(t_string *buf, const char *format, va_list ap)
{
	t_string	converted;
	t_status	stat;

	converted.len = 0;
	while (*format)
	{
		if (*format == '%')
			stat = convert_specifier(&converted, &format, ap);
		else
			stat = convert_simple_str(&converted, &format);
		if (stat == ERROR)
			return (ERROR);
		stat = append_string(buf, &converted);
		ft_free((void **) &converted.str);
		if (stat == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_string	buf;
	int			ret;

	va_start(ap, format);
	if (init_t_string(&buf) == ERROR)
		return (-1);
	if (get_buf(&buf, format, ap) == ERROR)
	{
		ft_free((void **) &buf.str);
		return (-1);
	}
	va_end(ap);
	ret = write(STDOUT_FILENO, buf.str, buf.len);
	ft_free((void **) &buf.str);
	return (ret);
}
