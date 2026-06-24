.PHONY : all clean fclean re

NAME = bureaucrat

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
endif

INC = .I-

SRC += main.cpp
SRC += Bureaucrat.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

$(NAME) : all

$(SRC) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $(SRC)

-include $(DEP)
clean :
	rm -fr $(OBJ) $(DEP)
fclean : clean
	rm -fr $(NAME)
re : fclean all


