# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svet <svet@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 15:46:13 by skrasin           #+#    #+#              #
#    Updated: 2020/07/10 22:02:56 by svet             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Sources
srcdir := ./srcs/
srcdirs := ctype mem str io math list
srcdirs_bonus := list_bonus

#	Includes
incdir := ./includes/

#	Libraries
LIBDIR		=	
LIB			=	

#	Output
NAME := libft.a

#	Compiler
CFLAGS := -Ofast -Wall -Wextra -Werror -pedantic# -Weverything
CPPFLAGS := -I$(incdir)

#	Archive
ARFLAGS := $(ARFLAGS)s

#################
##  AUTO       ##
#################

SHELL := /bin/sh
objects := $(patsubst %.c, %.o, $(foreach dir, $(addprefix $(srcdir), $(srcdirs)), $(wildcard $(dir)/*.c)))
objects_bonus := $(patsubst %.c, %.o, $(wildcard $(addprefix $(srcdir), $(srcdirs_bonus))/*.c))
# .PRECIOUS: %.o

#################
##  TARGETS    ##
#################

#	First target
all: $(NAME)

#	Archiving
$(NAME) : $(NAME)($(objects))

#	Bonus
bonus : $(NAME)($(objects_bonus))

#	Removing objects
clean:
	-$(RM) $(objects) $(objects_bonus)

#	Removing objects and archive
fclean: clean
	-$(RM) $(NAME)

#	All removing then compiling
re: fclean all

.PHONY: all clean fclean re bonus srcs includes ctype mem str io math list list_bonus
