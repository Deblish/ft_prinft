# Name of the library
NAME = libftprintf.a

# Executable name
EXECUTABLE = test

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror 
#-Wsign-conversion

# Directory locations
INC_DIR = ./include
SRC_DIR = ./src
LIBFT_DIR = ./libft

# Finding all .c files in src and libft directories
SRC_SOURCES = $(wildcard $(SRC_DIR)/*.c)
LIBFT_SOURCES = $(wildcard $(LIBFT_DIR)/*.c)

# Converting .c filenames to .o for both src and libft
SRC_OBJECTS = $(SRC_SOURCES:.c=.o)
LIBFT_OBJECTS = $(LIBFT_SOURCES:.c=.o)

# Default target
all: $(NAME)

# Executable rule
exe: $(EXECUTABLE)

# Creating the static library from both src and libft object files
$(NAME): $(SRC_OBJECTS) $(LIBFT_OBJECTS)
	ar rcs $@ $^

# Pattern rule for object files in src and libft directories
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Linking all object files to create the executable
$(EXECUTABLE): $(SRC_OBJECTS) $(LIBFT_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Cleaning up object files in both src and libft directories
clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(LIBFT_DIR)/*.o

# Cleaning everything that has been created, including the library
fclean: clean
	rm -f $(NAME)
	rm -f $(EXECUTABLE)

# Re-make everything
re: fclean all

# Mark rules as phony
.PHONY: all clean fclean re exe
