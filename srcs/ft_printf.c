/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:36:26 by jaham             #+#    #+#             */
/*   Updated: 2022/03/21 12:49:14 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_simple_str.h"
#include "libft.h"
#include "t_bool.h"
#include "t_string.h"
#include <limits.h>
#include <stdarg.h>

static t_status	append_buf(t_string *buf, t_string *converted)
{
	t_status	stat;

	stat = append_string(buf, converted);
	free(converted->str);
	if (stat == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static t_status	get_buf(t_string *buf, const char **format, va_list ap)
{
	t_string	converted;
	t_status	stat;
	t_bool		is_end;

	if (**format != '%')
	{
		stat = convert_simple_str(&converted, format);
		if (stat == ERROR)
			return (ERROR);
		if (append_buf(buf, &converted) == ERROR)
			return (ERROR);
	}
	if (**format == '%')
	{
		stat = convert_specifier(&converted, format, ap);
		if (stat == ERROR)
			return (ERROR);
		if (append_buf(buf, &converted) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_string	buf;
	ssize_t		ret;
	ssize_t		written;

	va_start(ap, format);
	if (init_t_string(&buf, "") == ERROR)
		return (-1);
	ret = 0;
	while (*format)
	{
		if (get_buf(&buf, &format, ap) == ERROR)
		{
			free(buf.str);
			return (-1);
		}
		written = write(STDOUT_FILENO, buf.str, buf.len);
		free(buf.str);
		if ((written == -1) || (ret + written > INT_MAX))
			return (-1);
		ret += written;
	}
	va_end(ap);
	return ((int) ret);
}
