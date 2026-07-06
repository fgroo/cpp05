.PHONY : all clean fclean re

NAME = bureaucrat

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
endif

INC = -I.

SRC += main.cpp
SRC += Bureaucrat.cpp
SRC += Form.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean :
	rm -fr $(OBJ) $(DEP) *.gch a.out
fclean : clean
	rm -fr $(NAME)
re : fclean all


