# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kessalih <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:24:36 by kessalih          #+#    #+#              #
#    Updated: 2021/11/15 15:50:20 by kessalih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CFILES = ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
			ft_split.c ft_strlen.c ft_strncmp.c ft_substr.c check_arg.c \
			ft_fill.c operations.c operations2.c push_a.c push_b.c sort.c \
			ft_strjoin.c ft_strdup.c ft_strlcpy.c ft_strlcat.c \
			ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c operations3.c
OFILES = $(CFILES:.c=.o)
OFILES_B = $(CFILES_B:.c=.o)
CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = push_swap.h
AR = ar rcs
RM = rm -rf
NAME = push_swap.a

%.o : %.c
	$(CC) $(FLAGS) $< -c $(HEADER)
	$(AR) $(NAME) $@

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) main2.c $(NAME) -o push_swap

all : $(NAME)

clean :
	$(RM) $(OFILES) $(OFILES_B)

fclean : clean
	$(RM) $(NAME) push_swap

re : fclean all

.PHONY : all re clean fclean
