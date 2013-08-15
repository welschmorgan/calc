TARGET_NAME=calc
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g

OBJ_DIR=./obj
SRC_DIR=./src
INC_DIR=./inc

CPL=$(CC) $(CFLAGS) -c -I$(INC_DIR)
LNK=$(CC) -o $(TARGET_NAME)

OBJS=$(OBJ_DIR)/main.o $(OBJ_DIR)/list.o

all: clean $(OBJS)
	$(LNK) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS)
	rm -rf $(TARGET_NAME)

$(OBJ_DIR)/main.o:
	$(CPL) $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/list.o:
	$(CPL) $(SRC_DIR)/list.c -o $(OBJ_DIR)/list.o
