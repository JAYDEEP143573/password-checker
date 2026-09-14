CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = password_checker
SRC = password_checker.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
