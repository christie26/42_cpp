NAME		= zombie

SRCS		= 	main.cpp Zombie.cpp \
				zombieHorde.cpp

OBJS		:= $(SRCS:%.cpp=%.o)

CPP 		= c++ -std=c++98
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all:		${NAME}

.cpp.o:
			$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
			$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re
