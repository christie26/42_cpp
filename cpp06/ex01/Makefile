NAME		=	a.out

SRCS		= 	main.cpp

OBJS		:= $(SRCS:%.cpp=%.o)

CFLAGS		= -std=c++98 -Wall -Wextra -Werror -g

all:		${NAME}

.cpp.o:
			$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
			$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			
			make fclean
			make all
.PHONY:		all clean fclean re
