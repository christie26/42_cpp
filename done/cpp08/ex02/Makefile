NAME		=	a.out

SRCS		= 	main.cpp

OBJS		:= $(SRCS:%.cpp=%.o)

CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror
ifdef DEBUG
	CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
endif

ifdef LOG
	CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -DLOG=1
endif

all:		${NAME}

.cpp.o:
			$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			
			make fclean
			make all
debug:		fclean
			make DEBUG=1 -j
log:
			make LOG=1
.PHONY:		all clean fclean re debug log
