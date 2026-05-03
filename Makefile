CC=gcc
CFLAGS=-Wall -Wextra -Itask6/include

SRC_DIR=task6/src
OBJ_DIR=task6/obj
BIN_DIR=task6/bin

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TARGET=$(BIN_DIR)/solution.exe

all: $(BIN_DIR) $(OBJ_DIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

run: $(TARGET)
	./$(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean run
