CC= gcc
CFLAGS= -Wall -g -I. -lm
TARGET= main
CFILES= main.c bubble.c 

all :
	$(CC) -o $(TARGET) $(CFILES) $(CFLAGS)

run :
	./$(TARGET)