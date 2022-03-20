/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:42:07 by jaham             #+#    #+#             */
/*   Updated: 2022/03/20 22:45:26 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_string.h"
#include <stdarg.h>

t_status	convert_specifier(
	t_string *converted, const char **format, va_list ap
)
{
	int	op;

	(*format)++;

}
