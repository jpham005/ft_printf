# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaham <jaham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 21:16:27 by jaham             #+#    #+#              #
#    Updated: 2022/03/20 22:25:06 by jaham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	cc
CFLAGS		:=	-g
RM			:=	rm
RMFLAGS		:=	-f
AR			:=	ar
ARFLAGS		:=	rcus
NAME		:=	libftprintf

# LIBFT_DIR	=	libft
# LIBFT		=	$(LIBFT_DIR)/libft.a

SRCS_DIR	:=	srcs
SRCS		:=	ft_printf.c convert_simple_str.c manage_t_string.c
SRCS		:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

# .PHONY	:	all
# all		:	$(NAME)

# $(NAME)	:	 $(LIBFT) $(OBJS)
# 	$(AR) $(ARFLAGS) $@ $(OBJS)

# .c.o	:
# 	$(CC) $(CFLAGS) -c $< -L$(LIBFT_DIR) -lft -I$(LIBFT_DIR)

# $(LIBFT)	:
# 	make all -C $(LIBFT_DIR)

# .PHONY	:	clean
# clean	:
# 	$(RM) $(RMFLAGS) $(OBJS)
# 	make clean -C $(LIBFT_DIR)

# .PHONY	:	fclean
# fclean	:	clean
# 	$(RM) $(RMFLAGS) $(NAME)
# 	make fclean -c $(LIBFT_DIR)
all	:
	$(CC) $(CFLAGS) main.c $(SRCS) -Iincludes libft/libft.a -Ilibft