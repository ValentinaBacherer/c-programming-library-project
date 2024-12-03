# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vabacher <vabacher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 11:50:20 by vabacher          #+#    #+#              #
#    Updated: 2024/12/03 09:28:13 by vabacher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler (how)
CC = cc

# Flags (how)
CFLAGS = -Wall -Werror -Wextra

# Library (what)
NAME = libft.a

# Source files (from what)
SRC = ft_isalpha.c ft_isdigit.c ft_strlen.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_strlcat.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_strlcpy.c ft_memmove.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
		ft_memchr.c ft_memcmp.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

# Source for bonus (from what)
BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c

# Object files
OBJ = $(SRC:.c=.o)

# Object files for bonus
BONUS_OBJ = $(BONUS:.c=.o)
# Rules

# Default rule
all: $(NAME)

# Build library
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

# Rule to compile c files into o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Rule to clean all files
fclean: clean
	rm -f $(NAME)

# Rule to rebuild
re: fclean all

# Rule for bonus
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	ranlib $(NAME)

# Phony targets
.PHONY: all clean fclean re bonus