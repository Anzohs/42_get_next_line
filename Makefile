# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hladeiro <hladeiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 19:56:26 by hladeiro          #+#    #+#              #
#    Updated: 2024/05/03 20:03:07 by hladeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC							= get_next_line.c get_next_line_utils.c

OBJS						= $(SRC:.c=.o)

CC							= cc
RM							= rm -f
CFLAGS						= -Wall -Wextra -Werror

Name						= get_next_line.a


all:						$(Name)
$(Name):					$(OBJS)
								ar	rcs	$(Name) $(OBJS)


clean:
								$(RM) $(OBJS)

fclean:						clean
								$(RM) $(Name)

re:							fclean	$(Name)