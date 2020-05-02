##
## ARTHUR MASSANES PROJECT, 2020
## game of life
## File description:
## makefile
##


NAME 		= 	gameOfLife

INCLUDE_PATH		=	include/

SRC_PATH	=	./src/

CLEAN		=	clean
FCLEAN		=	fclean
CXX			=	g++
LD			=	$(CXX)
PRINT		=	@echo -e
RM          =   @rm -f

override CPPFLAGS 	+=	-W -Wall -Werror -Wextra -std=c++11 -I./$(INCLUDE_PATH)

SRC		=	$(SRC_PATH)main.cpp	\
			$(SRC_PATH)Board.cpp

OBJ 	= 	$(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(LD) $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(RM) $(NAME)

re: fclean all
