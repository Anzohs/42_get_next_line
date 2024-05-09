SRC							= get_next_line.c get_next_line_utils.c

OBJS						= $(SRC:.c=.o)

CC							= cc
RM							= rm -f
CFLAGS						= -Wall -Wextra -Werror

Name						= next_line.a


all:						$(Name)
$(Name):					$(OBJS)
								ar	rcs	$(Name) $(OBJS)


clean:
								$(RM) $(OBJS)

fclean:						clean
								$(RM) $(Name)

re:							fclean	$(Name)