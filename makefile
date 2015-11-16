CC = gcc
CFLAGS = -Wall -ansi -g
SRC = cipher.c test_cipher.c
OBJS = $(SRC:.c=.o)

EXEC = run

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) $< -c $^

clean:
	rm $(EXEC) *.o
