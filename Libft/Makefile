# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 15:46:13 by skrasin           #+#    #+#              #
#    Updated: 2019/12/03 16:32:52 by skrasin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs
SOURCES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
			ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
			ft_strstr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_memalloc.c \
			ft_memdel.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
			ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
			ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c \
			ft_strsplit.c ft_strsub.c ft_strtrim.c ft_putstr.c ft_lstnew.c \
			ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstdel.c ft_lstdelone.c \
			ft_lstrev.c ft_display_file.c ft_read_write.c ft_print_bits.c \
			ft_swap_p.c ft_islower.c ft_isupper.c ft_mempcpy.c ft_get_next_line.c \
			
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I libft.h

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(INCLUDES) $(SOURCES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all