SRCS		= megaphone.cpp

OBJS		:= $(SRCS:%.cpp=%.o)

NAME		= megaphone

CPP 		= c++ -std=c++98
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all:		${NAME}

.c.o:
			$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS) $(LIBFT)
			$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re