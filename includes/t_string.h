/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:39:48 by jaham             #+#    #+#             */
/*   Updated: 2022/03/20 22:30:43 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STRING_H
# define T_STRING_H

# include "t_status.h"
# include <ctype.h>

typedef struct s_string
{
	char	*str;
	size_t	len;
}	t_string;

t_status	init_t_string(t_string *string);
t_status	append_string(t_string *s1, t_string *s2);

#endif