# Makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c11
# Source files
SRCS = minsuKim_assignment3.c
# Output
TARGET = minsuKim_assignment3.out
# Default target
all: $(TARGET)
# Rule to build the executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)
# Rule to run the program
run: $(TARGET)
	./$(TARGET)
# Rule to clean generated files
clean:
	rm -f $(TARGET)