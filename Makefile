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

LIB	= -lsfml-window -lsfml-system -lsfml-graphics

override CPPFLAGS 	+=	-W -Wall -Werror -Wextra -std=c++11 -I./$(INCLUDE_PATH) -g3

SRC		=	$(SRC_PATH)main.cpp	\
			$(SRC_PATH)Board.cpp	\
			$(SRC_PATH)Game.cpp	\
			$(SRC_PATH)Error.cpp	\

OBJ 	= 	$(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(LD) $(LIB) $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(RM) $(NAME)

re: fclean all
