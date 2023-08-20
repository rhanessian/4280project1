CC = gcc
CFLAGS = -g -Wall

TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CLFAGS) -o $(TARGET) $(TARGET).c scanner.c testScanner.c
	
clean:
	$(RM) $(TARGET)