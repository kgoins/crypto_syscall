CC = gcc
CFLAGS = -Wall -ansi
SRC = driver_cipher.c cipher.c cipherAlgs.c
OBJS = $(SRC:.c=.o)

EXEC = run

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) $< -c $^

clean:
	rm $(EXEC) *.o
