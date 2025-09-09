TARGET = torres_shell
OBJ = main.c input_parser.c helpers.c CommandParser.c executor.c
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: 
	$(CC) -o $(TARGET) $(OBJ)
clean:
	rm -f *-o
fclean:
	rm -f $(TARGET)
re: fclean all