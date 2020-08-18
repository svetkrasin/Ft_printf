# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svet <svet@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/14 18:30:04 by svet              #+#    #+#              #
#    Updated: 2020/08/17 15:48:50 by svet             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Sources
srcdir := ./srcs/
srcdirs := builder getter parser printf processor

#	Includes
incdir := ./Libft/includes ./includes
includes := ./Libft/includes/Makefile

#	Libraries
LIBDIR		=	Libft
LIB			=	

#	Output
NAME := libftprintf.a

#	Compiler
CFLAGS := -Ofast -Wall -Wextra -Werror -pedantic# -Weverything
CPPFLAGS := $(addprefix -I,$(incdir))

#	Archive
ARFLAGS := $(ARFLAGS)s

#################
##  AUTO       ##
#################

SHELL := /bin/sh
objects := $(patsubst %.c, %.o, $(foreach dir, $(addprefix $(srcdir), $(srcdirs)), $(wildcard $(dir)/*.c)))
#.PRECIOUS: %.o

#################
##  TARGETS    ##
#################

#	First target
all: $(NAME)

#	Archiving
# $(NAME) : $(NAME)($(objects))
# 	make -C Libft
$(NAME): $(objects)
	@make -C Libft
	@cp Libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(objects)
	@ranlib $(NAME)

#	Removing objects
clean:
	-$(RM) $(objects)
	make clean -C Libft

#	Removing objects and archive
fclean: clean
	-$(RM) $(NAME)
	make fclean -C Libft

#	All removing then compiling
re: fclean all

.PHONY: all clean fclean re srcs includes
