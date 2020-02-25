NAME = nibbler

SRC_DIR :=	./src/
OBJ_DIR :=	./obj/
INC_DIR :=	./inc/

SRC = 	main.cpp

		

#	project object files
OBJ =       $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

INCLUDES	=	-I $(INC_DIR)


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