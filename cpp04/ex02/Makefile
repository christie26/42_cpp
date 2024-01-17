NAME		=	a.out

SRCS		= 	main.cpp \
				Animal.cpp Dog.cpp Cat.cpp \
				WrongAnimal.cpp WrongDog.cpp WrongCat.cpp \
				PrintColor.cpp Brain.cpp

OBJS		:= $(SRCS:%.cpp=%.o)

CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -g

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
.PHONY:		all clean fclean re
