# Makefile for stacki.h, stack.cpp, and stackUI.cpp

# Compiler options
CC = g++
CFLAGS = -g -std=c++11 -Wall

OBJECT_DIR = obj

# Object files
OBJECTS = $(OBJECT_DIR)/cards.o $(OBJECT_DIR)/main.o

#srcDir
SRC_DIR = src

# Targets
all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main

cards: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o cards

$(OBJECT_DIR)/cards.o: $(SRC_DIR)/cards.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/cards.cpp -o $(OBJECT_DIR)/cards.o

$(OBJECT_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJECT_DIR)/main.o

run: main
	./main

clean:
	rm -f $(OBJECTS) $(OBJECTS_TEST) cards