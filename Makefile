NAME = nibbler

SRC_DIR :=	./src/
OBJ_DIR :=	./obj/
INC_DIR :=	./inc/

SRC = 	main.cpp				\
		core/Core.cpp 			\
		core/Tile.cpp			\
		core/MapBuilder.cpp 	\
		core/SnakeSpawner.cpp 	\
		core/Snake.cpp			\
		core/FruitSpawner.cpp 	\
		core/Fruit.cpp			\
		\
		parser/Parser.cpp


		

#	project object files
OBJ =       $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

INCLUDES	=	-I $(INC_DIR)			\
				-I $(INC_DIR)/utility 	\
				-I $(INC_DIR)/core 		\
				-I $(INC_DIR)/parser


CC_FLAGS := -Wall -Wextra -Werror -O3
CC = clang++ -std=c++14

all:
	make $(NAME)

# compiles .c files
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(INCLUDES) 
	# $(FRAMEWORKS) 
	# -g -fsanitize=address
	@ echo "\n===> $(NAME) compiled\n"

#compiles .o files
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS) $(INCLUDES)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

vpath %.cpp $(SRC_DIR)