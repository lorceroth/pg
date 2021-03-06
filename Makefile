VERSION = "0.1"
CC = gcc
CFLAGS = -DDEBUG=1 -DVERSION=$(VERSION)
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = pg

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o bin/$(TARGET) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# .PHONY: clean
clean:
	$(RM) src/*.o *~ $(TARGET)