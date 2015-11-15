CC = gcc
CFLAGS = -Wall -ansi -pthread
SRC = hello_pthread.c
OBJS = $(SRC:.c=.o)

EXEC = cipher

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) $< -c $^

clean:
	rm $(EXEC) *.o
