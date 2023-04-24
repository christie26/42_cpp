GREEN       =   "\033[0;32m"
PURPLE      =   "\033[0;35m"
WHITE       =   "\033[1;37m"
EOC         =   "\033[0;0m"

all:		clean

clean:
			@make -C ./ex00 fclean
			@echo $(WHITE)"ex00 - delete all object, binary files"$(EOC)
			@make -C ./ex01 fclean
			@echo $(WHITE)"ex01 - delete all object, binary files"$(EOC)
			@make -C ./ex02 fclean
			@echo $(WHITE)"ex02 - delete all object, binary files"$(EOC)
			@echo $(GREEN)"now ready to git commit"$(EOC)

.PHONY:		all clean
